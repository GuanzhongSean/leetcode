package main

import (
	"fmt"
	"q137/solution"
)

// Test cases
func main() {
	solver := solution.Solution{}
	testCases := []struct {
		nums     []int
		expected int
	}{
		{[]int{2, 2, 3, 2}, 3},
		{[]int{0, 1, 0, 1, 0, 1, 99}, 99},
		{[]int{-2, -2, -3, -2}, -3},
		{[]int{30000, 500, 100, 30000, 100, 30000, 100}, 500},
	}

	for _, tc := range testCases {
		result := solver.SingleNumber(tc.nums)
		if result == tc.expected {
			fmt.Printf("PASS: nums=%v expected=%v result=%v\n", tc.nums, tc.expected, result)
		} else {
			fmt.Printf("FAIL: nums=%v expected=%v result=%v\n", tc.nums, tc.expected, result)
		}
	}
}
