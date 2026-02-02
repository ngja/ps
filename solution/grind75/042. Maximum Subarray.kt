import kotlin.math.max

class Solution {

    // -2
    // dp[0] = -2
    // -2, 1
    // dp[1] == max(dp[0], dp[0]+nums[1], nums[1])
    fun maxSubArray(nums: IntArray): Int {
        val dp = IntArray(nums.size) { -10001 }

        dp[0] = nums[0]
        for (i in 1 until nums.size) {
            dp[i] = max(dp[i-1]+nums[i], nums[i])
        }

        var result = -10001
        for(n in dp) {
            result = max(result, n)
        }
        return result
    }
}

fun main(args: Array<String>) {

    val solution = Solution()
    val ans = solution.maxSubArray(intArrayOf(-2,-5, -1, -10, -20))
    println(ans)
}