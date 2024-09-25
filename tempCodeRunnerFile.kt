fun main() {
    val tt = readLine()!!.toInt()
    repeat(tt) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }

        var left = 0
        var leftCount = 0
        var right = n - 1
        var rightCount = 0

        while (left < n && a[left] == a[0])
        {
            left++
            leftCount++
        }
        while (right >= 0 && a[right] == a[n - 1])
        {
            right--
            rightCount++
        }

        if (a[0] == a[n - 1]) println(maxOf(0, n - (leftCount + rightCount)))
        else println(minOf(n - leftCount, n - rightCount))
    }
}
