class Solution {
    fun sortedSquares(nums: IntArray): IntArray {

        var lo = 0
        var hi = nums.size - 1

        val result = ArrayDeque<Int>()

        while (lo <= hi) {
            val loSquare = nums[lo] * nums[lo]
            val hiSquare = nums[hi] * nums[hi]

            if (hiSquare > loSquare) {
                result.addFirst(hiSquare)
                hi--
            } else {
                result.addFirst(loSquare)
                lo++
            }
        }

        return result.toIntArray()
    }
}

fun main(args: Array<String>) {

    val sol = Solution()
    val ans = sol.sortedSquares(intArrayOf(-7, -3, 2, 3, 11))
    println(ans.contentToString())
}