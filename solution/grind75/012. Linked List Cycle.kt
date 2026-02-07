/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    val addresses = mutableSetOf<ListNode?>()

    fun hasCycle(head: ListNode?): Boolean {
        return loop(head)
    }

    private fun loop(node: ListNode?): Boolean {
        if (node == null) {
            return false
        }
        if (addresses.contains(node)) {
            return true
        }
        addresses.add(node)
        return loop(node.next)
    }
}

fun main(args: Array<String>) {

}