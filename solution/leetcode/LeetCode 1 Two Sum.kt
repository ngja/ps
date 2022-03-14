import java.util.*

class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val numIndexMap = mutableMapOf<Int, Int>()
        for ((index, num) in nums.withIndex()) {
            val other = numIndexMap[target - num]

            if (other != null) {
                return intArrayOf(other, index)
            }

            numIndexMap[num] = index
        }
        return intArrayOf()
    }
}

fun main(args: Array<String>) {

    val s = Solution()
    val twoSum = s.twoSum(intArrayOf(2, 7, 11, 15), 9)
    println(twoSum.contentToString())

}