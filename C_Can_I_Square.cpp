#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    int tmp=sqrt(sum);
    cout<<(tmp*tmp==sum?"YES":"NO")<<endl;
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