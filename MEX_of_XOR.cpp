#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int L,R,X;
    cin>>L>>R>>X;
    int MEX=-1,lim=1000;
    for(int i=0;i<=lim;++i)
    {
        int val=i^X;
        if(val<L || val>R)
        {
            MEX=i;
            break;
        }
    }
    if(MEX==-1)MEX=lim+1;
    cout<<MEX<<endl;
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