class Solution {
    fun fourSum(nums: IntArray, target: Int): List<List<Int>> {
        val ans = mutableSetOf<List<Int>>()
        nums.sort()
        for (i in 0 until nums.size - 1) {
            for (j in i + 1 until nums.size - 1) {
                var k = j + 1
                var l = nums.size - 1

                while (k < l) {
                    val sum = nums[i].toLong() + nums[j] + nums[k] + nums[l]
                    if (sum > target) {
                        l -= 1
                    } else if (sum < target) {
                        k += 1
                    } else {
                        ans.add(listOf(nums[i], nums[j], nums[k], nums[l]))
                        l -= 1
                        k += 1
                    }
                }
            }
        }
        return ans.toList()
    }
}

fun main() {
    val solution = Solution()
    println(solution.fourSum(intArrayOf(1000000000,1000000000,1000000000,1000000000), -294967296))
    println(solution.fourSum(intArrayOf(2,2,2,2,2), 8))
}