#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=55,Mod=998244353;
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<int>Xor(n+1,0);
    for(int i=1;i<=n;++i)Xor[i]=Xor[i-1]^a[i];
    vector<vector<int>>Pref(N,vector<int>(n+1,0));
    for(int v=0;v<N;++v)
    {
        for(int i=1;i<=n;++i)
        {
            Pref[v][i]=Pref[v][i-1]+((a[i]==v)?1:0);
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int m=r-l+1;
        int ans=Pref[0][r]-Pref[0][l-1];
        if(ans>=1)
        {
            int tmp=ans;
            cout<<(m-1)<<" "<<(tmp%Mod)<<endl;
        }
        else if(Pref[0][r]>Pref[0][l-1])
        {
            int nim=Xor[r]^Xor[l-1];
            cout<<(m-1)<<" "<<(nim%Mod)<<endl;
            continue;
        }
        else
        {
            int P=0;
            for(int v=0;v<N;++v)
            {
                int cnt=Pref[v][r]-Pref[v][l-1];
                if(cnt>=2) P+=(1LL*cnt*(cnt-1))/2;
            }
            if(P>=1)
            {
                int tmp=P;
                cout<<(m-2)<<" "<<(tmp%Mod)<<endl;
            }
            else
            {
                int nim=Xor[r]^Xor[l-1];
                if(nim==0) cout<<"0 1"<<endl;
                else cout<<"-1"<<endl;
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}