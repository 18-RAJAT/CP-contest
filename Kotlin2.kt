import java.util.*
fun solve(n: Int)
{
    if(n==1)
    {
        println("-1")
        return
    }
    val Adjust=mutableListOf<Int>()
    Adjust.add(1)
    for(i in n downTo 2)
    {
        Adjust.add(i)
    }
    println(Adjust.joinToString(" "))
}

fun main()
{
    val scanner=Scanner(System.`in`)
    val t=scanner.nextInt()
    repeat(t)
    {
        val n=scanner.nextInt()
        solve(n)
    }
}