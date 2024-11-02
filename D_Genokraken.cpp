#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    n--;
    vector<int>a(n+1);
    int i=2,maxi=1;
    set<int>st;
    while(i<=n)
    {
        cout<<"? "<<1<<" "<<i<<endl;
        int x;
        cin>>x;
        st.insert(i);
        if(!x)
        {
            a[i]=1;
            break;
        }
        i++;
    }
    i++;
    while(i<=n)
    {
        auto it=st.upper_bound(maxi);
        // for(auto it=st.begin();it!=st.end();)
        // {
        //     int iter=*it;
        //     cout<<"? "<<iter<<" "<<i<<endl;
        //     int x;
        //     cin>>x;
        // }
        while(it!=st.end())
        {
            int iter=*it;
            cout<<"? "<<iter<<" "<<i<<endl;
            int x;
            cin>>x;
            if(!x)
            {
                a[i]=iter;
                maxi=max(maxi,iter);
                st.erase(iter);
                st.insert(i);
                break;
            }
            // else
            // {
            //     st.erase(iter);
            // }
            it++;
        }
        i++;
    }
    cout<<"! ";
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    cout<<endl;
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