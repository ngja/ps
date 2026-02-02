/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class TreeNode(val `val`: Int = 0) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    data class Info(
        val node: TreeNode,
        val height: Int,
        val parent: TreeNode?,
    )

    val treeInfoMap = mutableMapOf<Int, Info>()

    fun lowestCommonAncestor(root: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {
        dfs(root!!, 1, null)

        var pInfo = treeInfoMap[p!!.`val`]!!
        var qInfo = treeInfoMap[q!!.`val`]!!


        while (true) {
            if (pInfo.node.`val` == qInfo.node.`val`) {
                return pInfo.node
            }

            if (pInfo.height > qInfo.height) {
                pInfo = treeInfoMap[pInfo.parent!!.`val`]!!
            } else if (pInfo.height < qInfo.height) {
                qInfo = treeInfoMap[qInfo.parent!!.`val`]!!
            } else {
                pInfo = treeInfoMap[pInfo.parent!!.`val`]!!
                qInfo = treeInfoMap[qInfo.parent!!.`val`]!!
            }
        }
    }

    fun dfs(cur: TreeNode, height: Int, par: TreeNode?) {
        treeInfoMap.putIfAbsent(cur.`val`, Info(cur, height, par))

        if (cur.left != null) {
            dfs(cur.left!!, height + 1, cur)
        }
        if (cur.right != null) {
            dfs(cur.right!!, height + 1, cur)
        }
    }
}

fun main(args: Array<String>) {

}