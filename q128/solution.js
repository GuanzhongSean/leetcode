"use strict";
var __values = (this && this.__values) || function(o) {
    var s = typeof Symbol === "function" && Symbol.iterator, m = s && o[s], i = 0;
    if (m) return m.call(o);
    if (o && typeof o.length === "number") return {
        next: function () {
            if (o && i >= o.length) o = void 0;
            return { value: o && o[i++], done: !o };
        }
    };
    throw new TypeError(s ? "Object is not iterable." : "Symbol.iterator is not defined.");
};
Object.defineProperty(exports, "__esModule", { value: true });
var assert = require("assert");
function longestConsecutive(nums) {
    var e_1, _a;
    if (nums.length === 0)
        return 0;
    var numSet = new Set(nums);
    var longestStreak = 0;
    try {
        for (var numSet_1 = __values(numSet), numSet_1_1 = numSet_1.next(); !numSet_1_1.done; numSet_1_1 = numSet_1.next()) {
            var num = numSet_1_1.value;
            // Only start a new sequence if the number is the start of a sequence
            if (!numSet.has(num - 1)) {
                var currentNum = num;
                var currentStreak = 1;
                // Check for consecutive numbers
                while (numSet.has(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }
    }
    catch (e_1_1) { e_1 = { error: e_1_1 }; }
    finally {
        try {
            if (numSet_1_1 && !numSet_1_1.done && (_a = numSet_1.return)) _a.call(numSet_1);
        }
        finally { if (e_1) throw e_1.error; }
    }
    return longestStreak;
}
// Example usage:
var nums = [100, 4, 200, 1, 3, 2];
console.log(longestConsecutive(nums)); // Output: 4 (sequence: 1, 2, 3, 4)
// Test cases
var test1 = [100, 4, 200, 1, 3, 2];
assert.strictEqual(longestConsecutive(test1), 4);
var test2 = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1];
assert.strictEqual(longestConsecutive(test2), 9);
