class Solution {
    fun search(nums: IntArray, target: Int): Int {
        var left = 0
        var right = nums.size - 1

        while (left <= right) {
            val mid = (left + right).ushr(1)

            if (nums[mid] == target) {
                return mid
            } else if (nums[mid] > target) {
                right = mid - 1
            } else if (nums[mid] < target) {
                left = mid + 1
            }
        }

        return -1
    }
}

fun main(args: Array<String>) {

    val s = Solution()

    val intArray = intArrayOf(5)

    val result = s.search(intArray, 5)

    println(result)
}