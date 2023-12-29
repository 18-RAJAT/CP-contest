#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;    
    bool ok=false;
    set<int>st;
    st.insert(0);
    for(int i=0;i<n;++i)
    {
        i&1?ans-=a[i]:ans+=a[i];
        if(st.count(ans))
        {
            ok=true;
            break;
        }
        st.insert(ans);
    }
    cout<<(ok?"YES":"NO")<<endl;
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