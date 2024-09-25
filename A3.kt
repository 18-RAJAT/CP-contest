fun main()
{
    val t=readLine()!!.toInt()
    repeat(t)
    {
        val n=readLine()!!.toInt()
        val a=readLine()!!.split(" ").map{it.toInt()}
        var left=0;var Lc=0;var right=n-1;var Rc=0
        for(i in 0 until n)
        {
            if(left<n && a[0]==a[left]){left++;Lc++} else break
        }
        for(i in n-1 downTo 0)
        {
            if(right>=0 && a[n-1]==a[right]){right--;Rc++} else break
        }
        println(if(a[0]==a[n-1]) maxOf(0,n-(Lc+Rc)) else minOf(n-Lc,n-Rc))
    }
}