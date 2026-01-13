class ListNode(var `val`: Int) {
     var next: ListNode? = null
}

class Solution {

    fun removeFirst(list: ListNode?): ListNode? {
        if (list == null) {
            return null
        } else if (list.next == null) {
            return null
        }

        val result = ListNode(list.next!!.`val`)
        result.next = list.next!!.next
        return result
    }

    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        if (list1 == null && list2 == null) {
            return null
        } else if (list1 == null) {
            return list2
        } else if (list2 == null) {
            return list1
        }

        val merge = mutableListOf<Int>()

        var first = list1
        var second = list2
        while (first != null || second != null) {
            if (first == null) {
                merge.add(second!!.`val`)
                second = removeFirst(second)
            } else if (second == null) {
                merge.add(first.`val`)
                first = removeFirst(first)
            } else {
                if (first.`val` < second.`val`) {
                    merge.add(first.`val`)
                    first = removeFirst(first)
                } else {
                    merge.add(second.`val`)
                    second = removeFirst(second)
                }
            }
        }

        var result: ListNode? = null
        val reverseMerge = merge.reversed()
        for (element in reverseMerge) {
            if (result == null) {
                result = ListNode(element)
            } else {
                val temp = result
                result = ListNode(element)
                result.next = temp
            }
        }
        return result
    }
}

fun main(args: Array<String>) {
}