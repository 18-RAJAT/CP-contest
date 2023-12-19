#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a[1001];
    set<int>st;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        st.insert(x);
        a[x].push_back(i+1);
    }
    if(st.size()<k)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        
        cout<<"YES"<<endl;
        for(auto& it:st)
        {
            sort(a[it].begin(),a[it].end());
            cout<<a[it][0]<<" ";
            k--;
            if(k==0)
            {
                break;
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}