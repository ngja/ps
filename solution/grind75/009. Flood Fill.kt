class Solution {
    val left = -1 to 0
    val right = 1 to 0
    val up = 0 to -1
    val down = 0 to 1
    val dirs = listOf(left, down, right, up)

    private fun isIn(y: Int, x: Int, height: Int, width: Int): Boolean {
        return (y >= 0) && (x >= 0) && (y < height) && (x < width)
    }

    fun floodFill(image: Array<IntArray>, sr: Int, sc: Int, color: Int): Array<IntArray> {
        val height = image.size
        val width = image[0].size
        val startingColor = image[sr][sc]
        val visited = Array<IntArray>(height) { IntArray(width) { 0 } }

        val queue = java.util.ArrayDeque<Pair<Int, Int>>()
        queue.add(sr to sc)

        while (queue.isNotEmpty()) {
            val cur = queue.removeFirst()
            image[cur.first][cur.second] = color
            visited[cur.first][cur.second] = 1

            for (dir in dirs) {
                val next = (cur.first + dir.first) to (cur.second + dir.second)

                if (isIn(next.first, next.second, height, width)) {
                    if (visited[next.first][next.second] == 1) {
                        continue
                    }
                    if (image[next.first][next.second] == startingColor) {
                        visited[next.first][next.second] = 1
                        queue.addLast(next)
                    }
                }
            }
        }
        return image
    }
}

fun main(args: Array<String>) {

    val solution = Solution()
    val image = arrayOf(
        intArrayOf(0,0,0),
        intArrayOf(0,0,0),
    )
    val floodFill = solution.floodFill(image, 0, 0, 0)
    println(floodFill.contentDeepToString())
}