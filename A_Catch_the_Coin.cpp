#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        cout<<((y<-1)?"NO":"YES")<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}