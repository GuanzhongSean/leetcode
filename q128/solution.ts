import * as assert from "assert";

function longestConsecutive(nums: number[]): number {
  if (nums.length === 0) return 0;

  const numSet = new Set(nums);
  let longestStreak = 0;

  for (const num of numSet) {
    // Only start a new sequence if the number is the start of a sequence
    if (!numSet.has(num - 1)) {
      let currentNum = num;
      let currentStreak = 1;

      // Check for consecutive numbers
      while (numSet.has(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = Math.max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
}

// Example usage:
const nums = [100, 4, 200, 1, 3, 2];
console.log(longestConsecutive(nums)); // Output: 4 (sequence: 1, 2, 3, 4)

// Test cases
let test1 = [100, 4, 200, 1, 3, 2];
assert.strictEqual(longestConsecutive(test1), 4);

let test2 = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1];
assert.strictEqual(longestConsecutive(test2), 9);
