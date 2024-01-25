#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int sum=0;
    set<int>s;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    while(k--)
    {
        if(s.empty())
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<(*s.begin()-sum)<<endl;
            sum+=(*s.begin()-sum);
            s.erase(s.begin());
        }
    }
}
signed main()
{
    sol();
    return 0;
}