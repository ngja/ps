package technic

class Lexicographic {
    companion object {
        fun nextPermutation(array: Array<Int>): Boolean {
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
    }
}

fun main() {
    val array = arrayOf(1, 2, 3)

    do {
        println(array.contentToString())
    } while(Lexicographic.nextPermutation(array))
}