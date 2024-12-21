import * as assert from "assert";

function isPalindrome(s: string): boolean {
  s = s.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();
  let i = 0,
    j = s.length - 1;
  while (i < j) {
    if (s[i] !== s[j]) return false;
    i++;
    j--;
  }
  return true;
}

// Test cases
let true_test_cases: string[] = ["A man, a plan, a canal: Panama", " "];

true_test_cases.forEach((test_case) => {
  assert.strictEqual(isPalindrome(test_case), true);
});

let false_test_cases: string[] = ["race a car"];

false_test_cases.forEach((test_case) => {
  assert.strictEqual(isPalindrome(test_case), false);
});
