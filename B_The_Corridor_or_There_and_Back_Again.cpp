#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[205];
    memset(a,0,sizeof(a));
    int mnElement=INT_MAX;
    for(int i=0;i<n;++i)
    {
        int d,s;
        cin>>d>>s;
        a[d]=s;

        int check=d+(s+1)/2;//2,2=2+(3)/2=3 same as 200,200=200+(201)/2=300
        mnElement=min<int>(mnElement,check);
    }
    cout<<mnElement-1<<endl;//3-1=2 and 200-1=199 ok passed.
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