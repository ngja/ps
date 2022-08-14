import kotlin.math.min

fun canNotMove(next: Pair<Int, Int>, border: Pair<Int, Int>): Boolean {
    return next.first < 0 || next.second < 0 || next.first >= border.first || next.second >= border.second
}

fun isBackward(beforeDir: Int, nextDir: Int): Boolean {
    return (beforeDir - nextDir) == 2 || (beforeDir - nextDir) == -2
}

fun main(args: Array<String>) {

    val (w, h) = readLine()!!.split(" ").map { it.toInt() }
    val map = Array(h) { readLine()!!.toCharArray() }

    // find c
    val cPos = mutableListOf<Pair<Int, Int>>()
    for ((y, row) in map.withIndex()) {
        for ((x, cell) in row.withIndex()) {
            if (cell == 'C') {
                cPos.add(y to x)
            }
        }
    }

    val dirs = arrayOf(0 to 1, 1 to 0, 0 to -1, -1 to 0) // → ↓ ← ↑
    val mirror = Array(4) { Array(h) { Array(w) { 100000 } } }

    val q = ArrayDeque<Pair<Int, Pair<Int, Int>>>()
    q.addLast(-1 to cPos[0])
    for (i in 0 until 4) {
        mirror[i][cPos[0].first][cPos[0].second] = 0
    }

    while (q.isNotEmpty()) {
        val (beforeDir, cur) = q.removeFirst()

        for ((index, dir) in dirs.withIndex()) {
            val next = (cur.first + dir.first) to (cur.second + dir.second)

            if (canNotMove(next, h to w))
                continue

            if (map[next.first][next.second] == '*')
                continue

            if (beforeDir != -1 && isBackward(beforeDir, index))
                continue

            var nextMirror = if (beforeDir == -1) 0 else mirror[beforeDir][cur.first][cur.second]
            if (beforeDir != -1 && beforeDir != index)
                nextMirror += 1

            if (mirror[index][next.first][next.second] <= nextMirror)
                continue

            q.addLast(index to next)
            mirror[index][next.first][next.second] = nextMirror
        }
    }

    var ans = 10000
    for (i in 0 until 4) {
        if (ans > mirror[i][cPos[1].first][cPos[1].second])
            ans = mirror[i][cPos[1].first][cPos[1].second]
    }
    println(ans)
}