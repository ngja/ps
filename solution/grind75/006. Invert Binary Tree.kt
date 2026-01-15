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
    fun invertTree(root: TreeNode?): TreeNode? {
        if (root == null) {
            return null
        }

        val ans = TreeNode(root.`val`)
        if (root.right != null) {
            ans.left = invertTree(root.right)
        }
        if (root.left != null) {
            ans.right = invertTree(root.left)
        }
        return ans
    }
}


fun main(args: Array<String>) {

    val solution = Solution()
}