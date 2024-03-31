#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),ans;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int Sum=0;
    multiset<int>s;
    for(int i=0;i<n;++i)
    {
        Sum+=a[i];
        s.insert(a[i]);
    }
    for(int i=0;i<n;++i)
    {
        Sum-=a[i];
        s.erase(s.find(a[i]));
        int End=*(--s.end());
        Sum-=End;
        if(Sum==End)
        {
            ans.push_back(i+1);
        }
        Sum+=End;
        s.insert(a[i]);
        Sum+=a[i];
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}