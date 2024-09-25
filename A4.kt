fun main()
{
    val t=readLine()!!.toInt()
    repeat(t)
    {
        val n=readLine()!!.toInt()
        val arr=LongArray(n+1)
        val take=readLine()!!.split(" ").map{it.toInt()}
        for(i in take)
        {
            arr[i]++
        }
        var temp: Long=0
        var ans: Long=0
        for(i in 0..n)
        {
            if (arr[i]<=0)continue
            ans+=temp*(arr[i]*(arr[i]-1))/2
            val calc=arr[i]*(arr[i]-1)*(arr[i]-2)/6
            ans+=calc
            temp+=arr[i]
        }
        println(ans)
    }
}