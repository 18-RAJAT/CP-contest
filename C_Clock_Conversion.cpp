#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    tuple<int,int,int>time;
    get<0>(time)=stoi(s.substr(0,2));
    get<1>(time)=stoi(s.substr(3,2));
    get<2>(time)=0;
    string str;
    if(get<0>(time)<12)
    {
        str="AM";
    }
    else
    {
        str="PM";
    }
    if(get<0>(time)==0)
    {
        get<0>(time)=12;
    }
    if(get<0>(time)>12)
    {
        get<0>(time)-=12;
    }
    cout<<setfill('0')<<setw(2)<<get<0>(time)<<":"<<setfill('0')<<setw(2)<<get<1>(time)<<" "<<str<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}