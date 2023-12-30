var TC=readline();
while(TC--)
{
    var a=readline();
    var b=a.split(' ');
    var c=[];//creating an array to store the values
    a[0]=parseInt(b[0]);
    a[1]=parseInt(b[1]);
    a[2]=parseInt(b[2]);
    if(a[0]<a[1])
    {
        var temp=a[0];
        a[0]=a[1];
        a[1]=temp;
    }
    const ans=0;
    while(a[0]>a[1])
    {
        a[0]-=a[2];
        a[1]+=a[2];
        ans++;
    }
    print(ans);
}