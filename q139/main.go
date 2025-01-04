package main

import "fmt"

func wordBreak(s string, wordDict []string) bool {
	n := len(s)
	dp := make([]bool, n+1)
	dp[0] = true
	for i := 1; i <= n; i++ {
		substr := s[0:i]
		for _, str := range wordDict {
			if len(str) <= i {
				dp[i] = dp[i-len(str)] && substr[len(substr)-len(str):] == str
				if dp[i] {
					break
				}
			}
		}
	}
	return dp[n]
}

func main() {
	testCases := []struct {
		str      string
		wordDict []string
		expected bool
	}{
		{"leetcode", []string{"leet", "code"}, true},
		{"applepenapple", []string{"apple", "pen"}, true},
		{"applepenapples", []string{"apple", "pen"}, false},
		{"catsandog", []string{"cats", "dog", "sand", "and", "cat"}, false},
	}

	for _, tc := range testCases {
		result := wordBreak(tc.str, tc.wordDict)
		if result == tc.expected {
			fmt.Printf("PASS: str=%v wordDict=%v expected=%v result=%v\n", tc.str, tc.wordDict, tc.expected, result)
		} else {
			fmt.Printf("FAIL: str=%v wordDict=%v expected=%v result=%v\n", tc.str, tc.wordDict, tc.expected, result)
		}
	}
}
