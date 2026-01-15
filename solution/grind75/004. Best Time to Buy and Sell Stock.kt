class Solution {
    fun maxProfit(prices: IntArray): Int {
        var minPrice = Int.MAX_VALUE
        var profit = 0

        for (price in prices) {
            if (price < minPrice) {
                minPrice = price
            }

            val tempProfit = price - minPrice

            if (tempProfit > profit) {
                profit = tempProfit
            }
        }
        return profit
    }
}

fun main(args: Array<String>) {

    val solution = Solution()
    val prices = intArrayOf(7, 1, 5, 3, 6, 4)
    val ans = solution.maxProfit(prices)
    println(ans)
}