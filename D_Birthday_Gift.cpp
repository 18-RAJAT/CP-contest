#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a(100005);
int n,x;
int bit_calculate(int Msb)
{
    int sz=0,Idx=-1,Xor=0,Or=0;
    for(int i=0;i<n;++i)
    {
        Xor^=a[i];
        int mask=abs(INT_MAX-(((long long)1<<(Msb+1))-1));
        if((mask&Xor)==(mask&Xor&x) && (Xor&((long long)1<<Msb))==0 && Xor<=x)
        {
            Or|=Xor,Xor=0,sz++,Idx=i;
        }
    }
    if(Idx!=n-1 || x<Or)
    {
        return 0;
    }
    return sz;
}
void sol()
{
    cin>>n>>x;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<31;++i)
    {
        ans=max(ans,bit_calculate(i));
    }
    cout<<(ans!=0?ans:-1)<<endl;
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