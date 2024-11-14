#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string pali=s;
    reverse(pali.begin(),pali.end());
    // if(s==string(s.rbegin(),s.rend()))
    if(s==pali)
    {
        cout<<0<<endl;
        return;
    }
    s.pop_back();
    // pali=s;
    pali.pop_back();
    string str=s;
    // reverse(str.begin(),str.end());
    if(n==2)
    {
        cout<<-1<<endl;
        return;
    }
    if(n%2==0)
    {
        string str=s,st=str;
        reverse(str.begin(),str.end());
        reverse(st.begin(),st.end());
        if(s==str && str==st)
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<1<<endl;
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