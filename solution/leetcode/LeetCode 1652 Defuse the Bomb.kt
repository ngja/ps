class Solution {
    fun decrypt(code: IntArray, k: Int): IntArray {
        val result = IntArray(code.size)
        if (k > 0) {
            for (i in result.indices) {
                result[i] = sumNext(code, i, k)
            }
        } else if (k < 0) {
            for (i in result.indices) {
                result[i] = sumPrevious(code, i, k)
            }
        } else {
            for (i in result.indices) {
                result[i] = 0
            }
        }
        return result
    }

    private fun sumNext(code: IntArray, index: Int, k: Int): Int {
        var sum = 0
        for (i in 1 .. k) {
            val target = (index + i) % code.size
            sum += code[target]
        }
        return sum
    }

    private fun sumPrevious(code: IntArray, index: Int, k: Int): Int {
        var sum = 0
        for (i in k .. -1) {
            val target = (index + i + code.size) % code.size
            sum += code[target]
        }
        return sum
    }
}

fun main() {
    val solution = Solution()
    println(solution.decrypt(intArrayOf(5, 7, 1, 4), 3).toList())
    println(solution.decrypt(intArrayOf(1, 2, 3, 4), 0).toList())
    println(solution.decrypt(intArrayOf(2, 4, 9, 3), -2).toList())
}