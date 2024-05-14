import kotlin.math.*
fun sol()
{
    val n=readLine()!!.toInt()
    when(n)
    {
        1->println(1)
        2->println(2)
        3->println(0)
        4->println(1)
        5->println(0)
        6-> println(0)
        7->println(1)
        else->println(0)
    }
}

fun main()
{
    val tt=readLine()!!.toInt()
    repeat(tt)
    {
        sol()
    }
}