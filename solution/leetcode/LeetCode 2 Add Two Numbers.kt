import java.util.Stack

class ListNode(var `val`: Int) {
     var next: ListNode? = null
}

class Solution {
     fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
          var cur1 = l1
          var cur2 = l2

          var sum = cur1!!.`val` + cur2!!.`val`
          var register = sum / 10
          sum %= 10

          val reverseAns = Stack<Int>()
          reverseAns.add(sum)
          cur1 = cur1.next
          cur2 = cur2.next

          while(cur1 != null || cur2 != null) {
               val v1 = cur1?.`val` ?: 0
               val v2 = cur2?.`val` ?: 0
               sum = v1 + v2 + register
               register = sum / 10
               sum %= 10

               reverseAns.add(sum)
               cur1 = cur1?.next
               cur2 = cur2?.next
          }

          if (0 != register) {
               reverseAns.add(register)
          }

          var ans: ListNode? = null
          while (reverseAns.isNotEmpty()) {
               val top = reverseAns.pop()
               val nextAns = ListNode(top)
               nextAns.next = ans
               ans = nextAns
          }
          return ans
     }
}

fun main(args: Array<String>) {
}