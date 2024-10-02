#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=1000000007,MAX=300005;
int factorial[MAX];
void sol()
{
    factorial[1]=1;factorial[2]=2;
    int L_pos=3,R_pos=3;
    for(int i=3;i<MAX;i+=2)
    {
        factorial[i]=(factorial[i-1]*(L_pos%Mod))%Mod;
        factorial[i+1]=(2*factorial[i])%Mod;
        L_pos+=R_pos++;
    }
}
signed main()
{
    sol();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; 
        cout<<factorial[n]%Mod<<endl;
    }
    return 0;
}