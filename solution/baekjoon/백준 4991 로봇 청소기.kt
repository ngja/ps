class Solution(private val w: Int, private val h: Int, private val room: Array<CharArray>) {
    private val dirs = arrayOf(0 to 1, 1 to 0, 0 to -1, -1 to 0) // → ↓ ← ↑
    private var robot: Pair<Int, Int> = 0 to 0
    private val allPositions: MutableList<Pair<Int, Int>> = mutableListOf()
    private var dist: Array<Array<Int>>

    init {
        for ((y, row) in room.withIndex()) {
            for ((x, cell) in row.withIndex()) {
                if (cell == '*') {
                    allPositions.add(y to x)
                } else if (cell == 'o') {
                    robot = y to x
                }
            }
        }

        allPositions.add(0, robot)
        dist = Array(allPositions.size) { Array(allPositions.size) { -1 } }
    }

    private fun canNotMove(pos: Pair<Int, Int>): Boolean {
        return (pos.first < 0) || (pos.second < 0) || (pos.first >= h) || (pos.second >= w)
    }

    private fun calculateDist() {
        for ((index, pos) in allPositions.withIndex()) {
            val floodFill = Array(h) { Array(w) { -1 } }
            val q = ArrayDeque<Pair<Pair<Int, Int>, Int>>() // <pos, dist>
            q.addLast(pos to 0)
            floodFill[pos.first][pos.second] = 0

            while (q.isNotEmpty()) {
                val (cur, d) = q.removeFirst()

                for (dir in dirs) {
                    val next = cur.first + dir.first to cur.second + dir.second

                    if (canNotMove(next))
                        continue

                    if (room[next.first][next.second] == 'x')
                        continue

                    if (floodFill[next.first][next.second] != -1)
                        continue

                    floodFill[next.first][next.second] = d + 1
                    q.addLast(next to d + 1)
                }
            }

            for ((nextIndex, nextPos) in allPositions.withIndex()) {
                if (pos == nextPos)
                    continue
                dist[index][nextIndex] = floodFill[nextPos.first][nextPos.second]
            }
        }
    }

    private fun nextPermutation(array: Array<Int>): Boolean {
        var i = array.size - 1
        while (i > 0 && array[i-1] >= array[i])
            i--

        if (i <= 0)
            return false

        var j = array.size - 1
        while (array[j] <= array[i - 1])
            j--

        // swap
        array[i - 1] = array[j].also { array[j] = array[i - 1] }

        j = array.size - 1
        while (i < j) {
            array[i] = array[j].also { array[j] = array[i] }
            i++
            j--
        }

        return true
    }

    fun answer(): Int {
        calculateDist()

        val order = Array(allPositions.size - 1) { it + 1 }
        var ans = Int.MAX_VALUE
        loop@ do {
            var before = 0
            var tempAns = 0
            for (value in order) {
                if (dist[before][value] == -1)
                    continue@loop
                tempAns += dist[before][value]
                before = value
            }
            if (ans > tempAns)
                ans = tempAns
        } while(nextPermutation(order))

        if (ans == Int.MAX_VALUE)
            return -1
        else
            return ans
    }
}

fun main(args: Array<String>) {

    while (true) {
        val (w, h) = readLine()!!.split(" ").map { it.toInt() }
        if (w == 0 && h == 0)
            break

        val room = Array(h) { readLine()!!.toCharArray() }
        val solution = Solution(w, h, room)
        println(solution.answer())
    }
}