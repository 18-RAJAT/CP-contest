#include<bits/stdc++.h>
using namespace std;
#define int long long
void timeCalculate(string a,string b)
{
    int time1=((a[0]-'0')*10+(a[1]-'0'))*60+(a[3]-'0')*10+(a[4]-'0');//convert to minutes
    int time2=((b[0]-'0')*10+(b[1]-'0'))*60+(b[3]-'0')*10+(b[4]-'0');//convert to minutes
    int time3=(time1+time2)/2;
    int hour=time3/60;
    int minute=time3%60;
    if(hour<10)
    {
        cout<<0;
    }
    cout<<hour<<":";
    if(minute<10)
    {
        cout<<0;
    }
    cout<<minute<<"\n";
}
signed main()
{
    string a,b;
    cin>>a>>b;
    timeCalculate(a,b);
    return 0;
}