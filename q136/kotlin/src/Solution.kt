package q136

class Solution {
    fun singleNumber(nums: IntArray): Int {
        var result: Int = 0
        for (num: Int in nums) {
            result = result xor num
        }
        return result
    }
}
