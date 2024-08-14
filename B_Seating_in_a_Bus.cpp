#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    if(n==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    vector<int>op(n+2,0);
    int ok=1;
    op[a[0]]=1;
    for(int i=1;i<n;++i)
    {
        int tmp=a[i];
        if(!op[tmp-1] && !op[tmp+1])
        {
            ok=0;
            break;
        }
        op[tmp]=1;
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