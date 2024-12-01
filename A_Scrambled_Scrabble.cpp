#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string S;
    cin>>S;
    int n=S.length(),VL=0,CL=0,cnts=0,G=0,Y=0;
    for(auto& c:S)
    {
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')VL++;
        else if(c=='N')cnts++;
        else if(c=='G')G++;
        else if(c=='Y')Y++;
        else CL++;
    }
    int ForV=VL+Y,ForC=CL+cnts+G+Y,ans=0;
    for(int s=min(ForV,n/3);s>=1;--s)
    {
        int ok=min({2*s,cnts,G});
        for(int j=ok;~j;--j)
        {
            int use=2*s-j,rem=cnts-j,res=G-j;
            int maxi=max(0LL,s-VL);
            if(maxi>Y)continue;
            int fl=Y-maxi,tot=CL+rem+res+fl;
            if(use>tot)continue;
            int temp=3*s+j;
            if(temp>ans)ans=temp;
            break;
        }
        if(ans>=3*s+min({2*s,cnts,G}))break;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}