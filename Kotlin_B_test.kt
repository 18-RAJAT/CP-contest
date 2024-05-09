fun solve()
{
    val (a,b)=readln().split(" ")
    if(a.last()==b.last())
    {
        if (a.length==b.length)
        {
            println("=")
            return
        }
        else
        {
            if(a.last()=='S')
            {
                if (b.length<a.length)
                {
                    println("<")
                    return
                }
                else
                {
                    println(">")
                    return
                }
            }
            else
            {
                if(b.length<a.length)
                {
                    println(">")
                    return
                }
                else
                {
                    println("<")
                    return
                }
            }
        }
    }
    else if(b.last()<a.last())
    {
        println("<")
        return
    }
    else 
    {
        println(">")
        return
    }
}

fun readInt()=readln().toInt()

fun main()
{
    var t=readInt()
    while(t>0)
    {
        solve()
        t--
    }
}