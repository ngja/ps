class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val numsWithIndex = nums.withIndex()
            .map { (index, value) -> index to value }
            .sortedWith(Comparator.comparing { it.second })

        println(numsWithIndex)

        var left = 0
        var right = numsWithIndex.size - 1

        while (left < right) {
            val sum = numsWithIndex[left].second + numsWithIndex[right].second

            if (sum < target) {
                left++
            } else if (sum > target) {
                right--
            } else {
                return intArrayOf(numsWithIndex[left].first, numsWithIndex[right].first)
            }
        }
        return intArrayOf(numsWithIndex[left].first, numsWithIndex[right].first)
    }
}

fun main(args: Array<String>) {

    val solution = Solution()
    val nums = intArrayOf(3, 2, 4)
    val target = 6

    val answer = solution.twoSum(nums, target)
    answer.forEach { println(it) }
}