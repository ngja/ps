class Solution {
    fun searchRange(nums: IntArray, target: Int): IntArray {
        if (nums.isEmpty()) {
            return intArrayOf(-1, -1)
        }

        var lo = 0
        var hi = nums.size

        while (lo < hi) {

            val mid = lo + (hi - lo) / 2

            if (nums[mid] >= target) {
                hi = mid
            } else {
                lo = mid + 1
            }
        }

        val left = if ((hi != nums.size) && (nums[hi] == target)) hi else -1

        lo = 0
        hi = nums.size

        while (lo < hi) {

            val mid = lo + (hi - lo) / 2

            if (nums[mid] > target) {
                hi = mid
            } else {
                lo = mid + 1
            }
        }

        val right = if ((hi != 0) && (nums[hi - 1] == target)) hi - 1 else -1

        return intArrayOf(left, right)
    }
}

fun main(args: Array<String>) {

    val solution = Solution()

    val intArray = intArrayOf(8)
    val searchRange = solution.searchRange(intArray, 6)
    println(searchRange[0])
    println(searchRange[1])
}