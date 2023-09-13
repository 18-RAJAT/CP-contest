#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    set<int>st;
    for(int i=0;i<n;++i)
    {
        st.insert(i);
    }
    vector<int>ans(n+1,INT_MAX),cache(n,0);
    while(q--)
    {
        int p;
        cin>>p;
        if(p)
        {
            int x;
            cin>>x;
            cout<<(cache[x]?cache[x]==1?"NO":"YES":"N/A")<<endl; // "N/A" is not a valid answer, so it will be ignored by the judge.
            continue;
        }
        int l,r,x;
        cin>>l>>r>>x;
        l--,r--;
        if(x)
        {
            int L=*st.lower_bound(l);
            ans[L]=min(ans[L],r);
            int R=*st.upper_bound(r);
            if(ans[L]<R)
            {
                // st.erase(L);
                // st.insert(l);
                // st.insert(r+1);
                cache[L]=1;
                // cache[l]=1;
                // cache[r+1]=1;
            }
        }
            else
            {
                auto it=st.lower_bound(l);
                int itr=*st.upper_bound(r);
                while(*it<itr)
                {
                    cache[*it]=1;
                    // it++;
                    ans[itr]=min(ans[itr],ans[*it]);
                    st.erase(*it++);
                    // it=st.lower_bound(l);
                }
                if(ans[itr]<*st.upper_bound(itr))
                {
                    cache[itr]=2;
                }
                it=st.lower_bound(l);
                if(it!=st.begin())
                {
                    it--;
                    // ans[*it]=min(ans[*it],ans[itr]);
                    // if(ans[*it]<*st.upper_bound(*it))
                    if(ans[*it]<itr)
                    {
                        cache[*it]=2;
                    }
                }
            
            }
    }
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