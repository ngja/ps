class Solution {
    fun threeSum(nums: IntArray): List<List<Int>> {

        val ans = mutableSetOf<List<Int>>()
        nums.sort()
        for ((index, a) in nums.withIndex()) {
            var lo = index + 1
            var hi = nums.size - 1

            while (lo < hi) {
                if (a + nums[lo] + nums[hi] == 0) {
                    ans.add(listOf(a, nums[lo], nums[hi]))
                    lo++
                    hi--
                } else if (a + nums[lo] + nums[hi] > 0) {
                    hi--
                } else {
                    lo++
                }
            }
        }

        return ans.toList()
    }
}

fun main(args: Array<String>) {
    val s = Solution()
    val threeSum = s.threeSum(listOf<Int>().toIntArray())
    println(threeSum)
}