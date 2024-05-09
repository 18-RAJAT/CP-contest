import kotlin.math.abs

fun main()
{
    val t=readLine()!!.toInt()
    repeat(t)
    {
        val s=readLine()!!

        val n=s.length
        val a=s[0].toInt()
        val b=s[n-1].toInt()

        val find_all=if(a<b) 1 else -1
        var jumps=0
        val ans=mutableListOf<Int>()
        var i=a
        while(i!=b+find_all)
        {
            for(j in 0 until n)
            {
                if(s[j].toInt()==i)
                {
                    jumps++
                    ans.add(j+1)
                }
            }
            i+=find_all
        }
        println("${abs(a-b)} $jumps")
        println(ans.joinToString(" "))
    }
}
