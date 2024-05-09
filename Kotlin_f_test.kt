fun recur(a: List<Int>, i: Int, HP: Long, G: Int, B: Int): Long {
    if (i >= a.size) return 0
    if (a[i] < HP) return 1 + recur(a, i + 1, HP + a[i] / 2, G, B)

    val ans = mutableListOf<Long>(0)

    if (G >= 1) ans.add(recur(a, i, HP * 2, G - 1, B))
    if (B >= 1) ans.add(recur(a, i, HP * 3, G, B - 1))
    return ans.maxOrNull()!!
}

fun main() {
    val t = readLine()!!.toInt()
    (1..t).forEach {
        val HP = readLine()!!.split(' ')[1].toLong()
        val a = readLine()!!.split(' ').map { it.toInt() }
        println(recur(a.sorted(), 0, HP, 2, 1))
    }
}
