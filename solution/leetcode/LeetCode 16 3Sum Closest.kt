import kotlin.math.abs

class Solution {
    fun threeSumClosest(nums: IntArray, target: Int): Int {
        nums.sort()

        var ans = Int.MAX_VALUE
        for (i in nums.indices) {
            var left = i + 1
            var right = nums.size - 1

            while (left < right) {
                val sum = nums[i] + nums[left] + nums[right]
                if (abs(ans - target) > abs(sum - target)) {
                    ans = sum
                }

                if (sum > target) {
                    right -= 1
                } else if (sum < target) {
                    left += 1
                } else {
                    return sum
                }
            }
        }
        return ans
    }
}

fun main() {
    val solution = Solution()
    println(solution.threeSumClosest(intArrayOf(-1,2,1,-4), 1))
    println(solution.threeSumClosest(intArrayOf(0, 0, 0), 1))
}