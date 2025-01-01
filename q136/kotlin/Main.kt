import q136.Solution
import kotlin.assert

fun main() {
    val solution = Solution()
    val nums = intArrayOf(2, 2, 1)
    val result = solution.singleNumber(nums)
    println(result)
    assert(result == 1)
}
