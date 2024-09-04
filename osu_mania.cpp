#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<string>a(n);
    for(auto& i:a)cin>>i;
    vector<int>ans;
    for(int i=n-1;i>=0;--i)
    {
        for(int j=0;j<4;++j)
        {
            if(a[i][j]=='#')
            {
                ans.push_back(j+1);
                break;
            }
        }
    }
    for(auto& it:ans)cout<<it<<" ";cout<<endl;
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