import java.util.*

class MyQueue() {
    val stack1 = Stack<Int>()
    val stack2 = Stack<Int>()

    fun push(x: Int) {
        stack1.add(x)
    }

    fun pop(): Int? {
        if (stack2.isNotEmpty()) {
            return stack2.pop()
        }
        if (stack1.isEmpty()) {
            return null
        }
        while (stack1.isNotEmpty()) {
            val a = stack1.pop()
            stack2.add(a)
        }
        return stack2.pop()
    }

    fun peek(): Int? {
        if (stack2.isNotEmpty()) {
            return stack2.peek()
        }
        if (stack1.isEmpty()) {
            return null
        }
        while (stack1.isNotEmpty()) {
            val a = stack1.pop()
            stack2.add(a)
        }
        return stack2.peek()
    }

    fun empty(): Boolean {
        return (stack1.isEmpty()) && (stack2.isEmpty())
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */

fun main(args: Array<String>) {

}