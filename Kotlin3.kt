fun main()
{
    var t=readLine()?.toIntOrNull()?:return
    while(t>=1)
    {
        t--
        var s=readLine()?:return
        var n=s.length
        var sum: Long=0
        var j=0
        var str=""
        for(i in 0..n-1)
        {
            if(s[i]=='+')
            {
                if(j!=0)
                {
                    var Digit1=""
                    var Digit2=""
                    var Digit3=""
                    var Digit4=""
                    Digit1=str[0].toString()
                    var nn = str.length
                    for(k in 1..nn-1)
                        Digit2+=str[k]
                    for(k in 0..nn-2)
                        Digit3+=str[k]
                    Digit4=str[nn-1].toString()
                    var Num1: Long=Digit1.toLong()
                    var Num2: Long=Digit2.toLong()
                    var Num3: Long=Digit3.toLong()
                    var Num4: Long=Digit4.toLong()
                    Num1+=Num2
                    Num3+=Num4
                    if(Num3<Num1)
                        sum+=Num1
                    else
                        sum+=Num3
                }
                str=""
                j=i+1
            }
            else
            {
                str+=s[i]
            }
        }
        str=""
        for(i in 0..n-1)
        {
            if(s[i]=='+')
            {
                var e: Long=str.toLong()
                sum+=e;
                break
            }
            str+=s[i]
        }
        str=""
        for(i in j..n-1)
            str+=s[i]
        var e: Long=str.toLong()
        sum+=e
        println(sum)
    }
}