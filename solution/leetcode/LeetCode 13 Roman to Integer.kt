class Solution {
    private val romanList = listOf(
        "IV" to 4,
        "IX" to 9,
        "XL" to 40,
        "XC" to 90,
        "CD" to 400,
        "CM" to 900,

        "M" to 1000,
        "D" to 500,
        "C" to 100,
        "L" to 50,
        "X" to 10,
        "V" to 5,
        "I" to 1,
    )

    fun romanToInt(s: String): Int {
        var ans = 0
        var str = s

        while (str != "") {
            for (roman in romanList) {
                if (str.startsWith(roman.first)) {
                    ans += roman.second
                    str = str.drop(roman.first.length)
                    break
                }
            }
        }

        return ans
    }
}

fun main(args: Array<String>) {

    val s = Solution()
    val result = s.romanToInt("MCMXCIV")
    println(result)
}