import kotlin.math.abs
import kotlin.math.max

/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class TreeNode(val `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    fun isBalanced(root: TreeNode?): Boolean {
        if (root == null) {
            return true
        }

        return height(root) != -1
    }

    /**
     * 현재 node의 높이, 만약
     */
    private fun height(node: TreeNode?): Int {
        if (node == null)
            return 0
        // 왼쪽 서브 트리 높이
        val leftHeight = height(node.left)
        // 오른쪽 서브 트리 높이
        val rightHeight = height(node.right)

        if (leftHeight == -1 || rightHeight == -1) {
            return -1
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1
        }


        // 왼트리 높이, 오른트리 높이 중 높은 것에 자기자신 1 더한게 자신의 높이
        return max(leftHeight, rightHeight) + 1
    }
}


fun main(args: Array<String>) {

}