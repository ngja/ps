
class Solution {
    fun searchInsert(nums: IntArray, target: Int): Int {
        var lo = 0
        var hi = nums.size

        while (lo < hi) {
            val mid = lo + (hi - lo) / 2

            if (target > nums[mid]) {
                lo = mid + 1
            } else {
                hi = mid
            }
        }

        return hi
    }
}

fun main(args: Array<String>) {

    val sol = Solution()

    val ans = sol.searchInsert(intArrayOf(10), 7)
    println(ans)
}