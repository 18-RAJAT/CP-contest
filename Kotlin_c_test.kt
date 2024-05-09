fun main()
{
    val t=readLine()!!.toInt()
    repeat(t)
    {
        val input=readLine()!!.split(" ")
        val n=input[0].toInt()
        val c=input[1][0]
        var s=readLine()!!
        var k=-1
        var ans=Int.MIN_VALUE
        s+=s
        for(i in s.length - 1 downTo 0)
        {
            if(s[i]=='g')
            {
                k=i
            }
            if(s[i]==c)
            {
                ans=maxOf(ans,k-i)
            }
        }
        println(ans)
    }
}