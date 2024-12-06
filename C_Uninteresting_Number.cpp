#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int last=0,c2=0,c3=0,inv2=5;
    for(auto& it:s)
    {
        int ch=it-'0';
        last=(last+ch)%9;
        if(ch==2)c2++;
        if(ch==3)c3++;
    }
    int M=(-last+9)%9;
    for(int i=0;i<3;++i)
    {
        int res=(6*i)%9;
        int P=(M-res+9)%9,Q=(inv2*P)%9;
        if(Q<=c2 && i<=c3)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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