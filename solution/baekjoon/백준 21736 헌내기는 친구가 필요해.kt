fun main(args: Array<String>) {
    val dirs = arrayOf(0 to 1, 1 to 0, 0 to -1, -1 to 0) // 우 하 좌 상
    val (n, m) = readln().split(" ").map { it.toInt() }
    val campus = Array(n) { readln().toCharArray() }
    val visited = Array(n) { BooleanArray(m) { false } }

    // 시작 위치 찾기
    var startPos = 0 to 0
    loop@ for (i in 0 until n) {
        for (j in 0 until m) {
            if (campus[i][j] == 'I') {
                startPos = i to j
                break@loop
            }
        }
    }

    // 시작위치에서 bfs
    val q = ArrayDeque<Pair<Int, Int>>()
    visited[startPos.first][startPos.second] = true
    q.addLast(startPos)

    var ans = 0
    while (q.isNotEmpty()) {
        val now = q.removeFirst()

        for (dir in dirs) {
            val next = now.first + dir.first to now.second + dir.second

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) {
                continue
            }

            if (visited[next.first][next.second]) {
                continue
            }

            if (campus[next.first][next.second] == 'X') {
                continue
            }

            if (campus[next.first][next.second] == 'P') {
                ans++
            }

            visited[next.first][next.second] = true
            q.addLast(next)
        }
    }
    if (ans == 0) {
        println("TT")
    } else {
        println(ans)
    }
}