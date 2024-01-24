#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s1,s2;
    cin>>s2>>s1;
    int pos11=s1[0]-'a'+1,pos12=s1[1]-'0';
    int pos21=s2[0]-'a'+1,pos22=s2[1]-'0';
    int ans=0;
    for(int i=1;i<=8;++i)
    {
        if(i==pos21)
        {
            continue;
        }
        for(int j=1;j<=8;++j)
        {
            if(j==pos22)
            {
                continue;
            }
            if(abs(pos11-i)==1 && abs(pos12-j)==2)
            {
                continue;
            }
            if(abs(pos11-i)==2 && abs(pos12-j)==1)
            {
                continue;
            }
            if(i==pos11 && j==pos12)
            {
                continue;
            }
            if(abs(pos21-i)==1 && abs(pos22-j)==2)
            {
                continue;
            }
            if(abs(pos21-i)==2 && abs(pos22-j)==1)
            {
                continue;
            }
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}