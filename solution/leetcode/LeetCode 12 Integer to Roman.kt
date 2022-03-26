class Solution {
    private val romanList = listOf(
        "M" to 1000,
        "CM" to 900,
        "D" to 500,
        "CD" to 400,
        "C" to 100,
        "XC" to 90,
        "L" to 50,
        "XL" to 40,
        "X" to 10,
        "IX" to 9,
        "V" to 5,
        "IV" to 4,
        "I" to 1
    )

    fun intToRoman(num: Int): String {
        var temp = num
        var ans = ""

        while (temp > 0) {
            for (roman in romanList) {
                if (roman.second <= temp) {
                    ans += roman.first
                    temp -= roman.second
                    break
                }
            }
        }

        return ans
    }
}

fun main(args: Array<String>) {

    val s = Solution()
    val result = s.intToRoman(1994)
    println(result)
}