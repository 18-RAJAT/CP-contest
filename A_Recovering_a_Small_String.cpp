#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,char>mp;
    for(int i=1;i<=26;++i)
    {
        mp[i]='a'+i-1;
    }
    string s;
    for(int i=1;i<=26;++i)
    {
        for(int j=1;j<=26;++j)
        {
            for(int k=1;k<=26;++k)
            {
                if(i+j+k==n)
                {
                    s+=mp[i];
                    s+=mp[j];
                    s+=mp[k];
                    cout<<s<<endl;
                    return;
                }
            }
        }
    }
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