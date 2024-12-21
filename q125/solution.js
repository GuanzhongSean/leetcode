"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var assert = require("assert");
function isPalindrome(s) {
    s = s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
    var i = 0, j = s.length - 1;
    while (i < j) {
        if (s[i] !== s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
;
// Test cases
var true_test_cases = [
    "A man, a plan, a canal: Panama",
    " "
];
var false_test_cases = [
    "race a car"
];
true_test_cases.forEach(function (test_case) {
    assert.strictEqual(isPalindrome(test_case), true);
});
false_test_cases.forEach(function (test_case) {
    assert.strictEqual(isPalindrome(test_case), false);
});
