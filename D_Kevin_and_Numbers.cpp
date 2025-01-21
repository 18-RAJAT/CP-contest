#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    int A=0,B=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        A+=a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
        B+=b[i];
    }
    if(A!=B)
    {
        cout<<"No"<<endl;
        return;
    }
    multiset<int>ms;
    for(int i=0;i<n;++i)ms.insert(a[i]);
    for(int i=0;i<m;++i)
    {
        vector<int>ans;
        ans.push_back(b[i]);
        while(!ans.empty())
        {
            int l=ans.back();
            ans.pop_back();
            if(ms.count(l))ms.erase(ms.find(l));
            else
            {
                if(l==1)
                {
                    cout<<"No"<<endl;
                    return;
                }
                ans.push_back(l/2);
                ans.push_back(l-l/2);
            }
        }
    }
    cout<<"Yes"<<endl;
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