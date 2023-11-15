#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int c=0;
    bool ok=false;
    for(int i=1;i<n;++i)
    {
        if(s[i]==s[0])
        {
            c++;
            for(int j=i+1;j<n;++j)
            {
                if(s[c]!=s[j])
                {
                    c=0;
                    break;
                }
                if(j==n-1)
                {
                    ok=true;
                }
                c++;
            }
        }
        if(ok==true)
        {
            break;
        }
    }
    cout<<s;
    for(int i=1;i<k;++i)
    {
        for(int j=c;j<n;++j)
        {
            cout<<s[j];
        }
    }
}
signed main()
{
    sol();
    return 0;
}