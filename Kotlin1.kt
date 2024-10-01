fun main()
{
    val t=readLine()!!.toInt()
    repeat(t)
    {
        val n=readLine()!!.toInt()
        val m=readLine()!!.split(" ").map{it.toInt()}.toMutableList()
        val ele=m.subList(0,n-1).maxOrNull()!!
        val check=m.last()
        if (ele==check-1)
        {
            println(ele)
        }
        else
        {
            println("Ambiguous")
        }
    }
}