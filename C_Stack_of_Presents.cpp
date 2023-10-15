#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(auto& it:a)
    {
        cin>>it;
    }
    int ctr1,ctr2;
    ctr1=ctr2=0;
    vector<int>pos(m);
    for(auto& it:pos)
    {
        cin>>it;
        // --it;    
    }
    multiset<int>st;
    int ans=0;
    while(ctr2<m)
    {
        if(st.find(pos[ctr2])!=st.end())
        {
            st.erase(st.find(pos[ctr2]));
            // ans+=a[pos[ctr2]];
            ans++;
        }
        // else if(pos[ctr2]==a[ctr1])
        // {
        //     ctr1++;
        //     ans++;
        // }
        // else if(st.find(a[ctr1])!=st.end())
        // {
        //     st.erase(st.find(a[ctr1]));
        //     ans++;
        //     ctr1++;
        // }
        else
        {
            int tmp=pos[ctr2];
            ans+=(2*(st.size()));
            // int vals=0;
            while(tmp!=a[ctr1])
            {
                // if(st.find(tmp)==st.end())
                // {
                //     st.insert(tmp);
                //     vals+=a[tmp];
                // }
                st.insert(a[ctr1]);
                ctr1++;
                //vals++;
                ans+=2LL;
                // tmp=pos[++ctr1];
            }
            ctr1++;
            //vals++;
            // int get=2*vals;
            ans++;
        }
        ctr2++;
    }
    cout<<ans<<"\n";
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