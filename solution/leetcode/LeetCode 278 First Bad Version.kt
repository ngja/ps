/* The isBadVersion API is defined in the parent class VersionControl.
      fun isBadVersion(version: Int) : Boolean {} */

open class VersionControl {

    open fun firstBadVersion(n: Int): Int {
        return 0
    }

    fun isBadVersion(version: Int): Boolean {
        return false
    }
}

class Solution: VersionControl() {
    override fun firstBadVersion(n: Int) : Int {

        var lo = 1
        var hi = n + 1

        while (lo < hi) {
            val mid = (lo + hi).ushr(1)

            val badVersion = isBadVersion(mid)

            if (badVersion) {
                hi = mid
            } else {
                lo = mid + 1
            }
        }

        return hi
    }
}
fun main(args: Array<String>) {

}