class Solution {
    fun removeElement(nums: IntArray, `val`: Int): Int {
        var k = 0
        val queue = mutableListOf<Int>()
        for (i in nums.indices) {
            if (nums[i] == `val`) {
                queue.add(i)
            } else {
                k += 1
                if (queue.isNotEmpty()) {
                    val targetIndex = queue.removeFirst()
                    nums[targetIndex] = nums[i]
                    queue.add(i)
                }
            }
        }
        return k
    }
}

fun main() {
    val solution = Solution()
    println(solution.removeElement(intArrayOf(3, 2, 2, 3), 3))
    println(solution.removeElement(intArrayOf(0,1,2,2,3,0,4,2), 2))
}