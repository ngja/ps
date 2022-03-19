class Solution {
    fun convert(s: String, numRows: Int): String {
        val substringList = List<MutableList<Char>> (numRows) { mutableListOf() }

        if (numRows == 1) {
            return s
        }

        var step = 0  // (step / (numRows - 1)) % 2 값이 0이면 증가 1이면 감소
        var index = 0
        for (c in s) {
            substringList[index].add(c)
            val nextIndex = nextIndex(step, numRows)
            index += nextIndex
            step++
        }

        return substringList.flatten().joinToString("")
    }

    private fun nextIndex(step: Int, numRows: Int): Int = if ((step / (numRows - 1)) % 2 == 0) 1 else -1
}

fun main(args: Array<String>) {
    val s = Solution()
    val ans = s.convert("A", 1)
    println(ans)
}