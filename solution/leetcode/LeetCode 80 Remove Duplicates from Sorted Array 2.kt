class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var ans = 1
        var leftIndex = 0
        var rightIndex = 1
        var sameNumberCount = 1
        for (index in 1 until nums.size) {
            nums[rightIndex] = nums[index]
            if (nums[leftIndex] != nums[rightIndex]) {
                ans++
                rightIndex++
                leftIndex++
                sameNumberCount = 1
            } else {
                sameNumberCount++
                if (sameNumberCount <= 2) {
                    ans++
                    rightIndex++
                    leftIndex++
                }
            }
        }
        return ans
    }
}

fun main(args: Array<String>) {
    val solution = Solution()

    val nums1 = intArrayOf(1, 1, 1, 2, 2, 3)
    val ans1 = solution.removeDuplicates(nums1)
    println(ans1)


    val nums2 = intArrayOf(0, 0, 1, 1, 1, 1, 2, 3, 3)
    val ans2 = solution.removeDuplicates(nums2)
    println(ans2)

    val nums3 = intArrayOf(1)
    val ans3 = solution.removeDuplicates(nums3)
    println(ans3)

    val nums4 = intArrayOf(1, 1, 1, 1, 1, 1, 1, 1)
    val ans4 = solution.removeDuplicates(nums4)
    println(ans4)
}