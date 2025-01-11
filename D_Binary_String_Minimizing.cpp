#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    set<int>st;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')st.insert(i);
    }
    for(int i=0;i<n && k;++i)
    {
        if(s[i]=='1')
        {
            auto LB=st.lower_bound(i);
            if(LB==st.end())break;
            if(*LB-i<=k)
            {
                swap(s[*LB],s[i]);
                k-=*LB-i;
            }
            else
            {
                swap(s[*LB],s[*LB-k]);
                k=0;
            }
            st.erase(LB);
        }
    }
    cout<<s<<endl;
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