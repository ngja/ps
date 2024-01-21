class Trie (
    private val food: String? = null,
    private val floor: Int = 0,
    private val children: MutableMap<String, Trie> = mutableMapOf()
) {
    override fun toString(): String {
        return "food=$food, floor=$floor, children=$children"
    }

    fun add(food: String): Trie {
        if (children[food] == null) {
            children[food] = Trie(food, this.floor + 1)
        }
        return children[food]!!
    }

    fun print() {
        val stack = ArrayDeque<Trie>()
        stack.addFirst(this)

        while (stack.isNotEmpty()) {
            val now = stack.removeFirst()
            val keys = now.children.keys.sortedDescending()
            for (key in keys) {
                stack.addFirst(now.children[key]!!)
            }

            if (now.food != null) {
                println("${now.getHyphen()}${now.food}")
            }
        }
    }

    private fun getHyphen(): String {
        return if (food == null) {
            ""
        } else {
            "--".repeat(floor - 1)
        }
    }
}

fun main(args: Array<String>) {
    val head = Trie()
    val n = readln().toInt()
    for (i in 0 until n) {
        val input = readln().split(" ")

        var now = head
        for (j in 1 until input.size) {
            val food = input[j]
            now = now.add(food)
        }
    }
    head.print()
}