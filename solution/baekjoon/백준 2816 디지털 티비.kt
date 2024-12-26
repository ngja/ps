class Solution {
    companion object {
        const val KBS1 = "KBS1"
        const val KBS2 = "KBS2"
    }

    fun change(channels: List<String>): String {
        var kbs1Pos = 0
        var kbs2Pos = 0
        for ((index, channel) in channels.withIndex()) {
            if (KBS1 == channel) {
                kbs1Pos = index
            } else if (KBS2 == channel) {
                kbs2Pos = index
            }
        }

        return if (kbs1Pos == 1 && kbs2Pos == 0) {
            "3"
        } else if (kbs1Pos < kbs2Pos) {
            command(kbs1Pos, kbs2Pos)
        } else {
            command(kbs1Pos, kbs2Pos + 1)
        }
    }

    private fun command(first: Int, second: Int): String {
        var c = ""
        for (i in 0 until first) {
            c += "1"
        }
        for (i in 0 until first) {
            c += "4"
        }
        for (i in 0 until second) {
            c += "1"
        }
        for (i in 0 until second - 1) {
            c += "4"
        }
        return c
    }
}

fun main() {
    val solution = Solution()
    val n = readln().toInt()
    val channels = mutableListOf<String>()
    for (i in 0 until n) {
        val channel = readln()
        channels.add(channel)
    }
    val ans = solution.change(channels)
    println(ans)
}