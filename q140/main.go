package main

import (
	"fmt"
)

func slicesEqualIgnoreOrder(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}

	count := make(map[string]int)

	for _, val := range a {
		count[val]++
	}

	for _, val := range b {
		count[val]--
		if count[val] < 0 {
			return false
		}
	}

	return true
}

func wordBreak(s string, wordDict []string) []string {
	n := len(s)
	result := []string{}
	cur := ""
	var helper func(int)
	helper = func(idx int) {
		if idx == n {
			result = append(result, cur)
			return
		}
		for _, word := range wordDict {
			if n-idx >= len(word) && s[idx:idx+len(word)] == word {
				tmp := cur
				if len(cur) == 0 {
					cur = word
				} else {
					cur = cur + " " + word
				}
				helper(idx + len(word))
				cur = tmp
			}
		}
	}
	helper(0)
	return result
}

func main() {
	testCases := []struct {
		str      string
		wordDict []string
		expected []string
	}{
		{"leetcode", []string{"leet", "code"}, []string{"leet code"}},
		{"pineapplepenapple", []string{"apple", "pen", "applepen", "pine", "pineapple"}, []string{"pine apple pen apple", "pineapple pen apple", "pine applepen apple"}},
		{"applepenapples", []string{"apple", "pen"}, []string{}},
		{"catsanddog", []string{"cat", "cats", "and", "sand", "dog"}, []string{"cats and dog", "cat sand dog"}},
		{"catsandog", []string{"cats", "dog", "sand", "and", "cat"}, []string{}},
	}

	for _, tc := range testCases {
		result := wordBreak(tc.str, tc.wordDict)
		if slicesEqualIgnoreOrder(result, tc.expected) {
			fmt.Printf("PASS: str=%v wordDict=%v expected=%v result=%v\n", tc.str, tc.wordDict, tc.expected, result)
		} else {
			fmt.Printf("FAIL: str=%v wordDict=%v expected=%v result=%v\n", tc.str, tc.wordDict, tc.expected, result)
		}
	}
}
