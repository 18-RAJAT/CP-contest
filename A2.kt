import kotlin.math.sqrt

fun solve()
{
    val n=readLine()!!.toInt()
    val s=readLine()!!
    val Sq=sqrt(n.toDouble()).toInt()
    if(Sq*Sq!=n)
    {
        println("No")
        return
    }
    for(i in 0 until Sq)
    {
        for(j in 0 until Sq)
        {
            val Valid_Track=if(i==0 || i==Sq-1 || j==0 || j==Sq-1) '1' else '0'
            if(s[i*Sq+j]!=Valid_Track)
            {
                println("No")
                return
            }
        }
    }
    println("Yes")
}
fun main()
{
    val t=readLine()!!.toInt()
    repeat(t)
    {
        solve()
    }
}