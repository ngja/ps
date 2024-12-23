class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var count = 1
        var base = nums.first()
        val queue = mutableListOf<Int>()
        for (i in 1 until nums.size) {
            if (base == nums[i]) {
                queue.add(i)
            } else {
                base = nums[i]
                count++
                if (queue.isNotEmpty()) {
                    val updateIndex = queue.removeFirst()
                    nums[updateIndex] = nums[i]
                    queue.add(i)
                }
            }
        }
        return count
    }
}

fun main() {
    val solution = Solution()
    println(solution.removeDuplicates(intArrayOf(1,1,2)))
    println(solution.removeDuplicates(intArrayOf(0,0,1,1,1,2,2,3,3,4)))
}