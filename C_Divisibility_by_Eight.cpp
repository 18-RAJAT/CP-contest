#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0' || s[i]=='8')
        {
            cout<<"YES"<<endl<<s[i];
            return;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if((10*(s[i]-'0')+(s[j]-'0'))%8==0)
            {
                cout<<"YES"<<endl<<s[i]<<s[j];
                return;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            for(int k=j+1;k<n;++k)
            {
                if((100*(s[i]-'0')+10*(s[j]-'0')+(s[k]-'0'))%8==0)
                {
                    cout<<"YES"<<endl<<s[i]<<s[j]<<s[k];
                    return;
                }
            }
        }
    }
    cout<<"NO";
}
signed main()
{
    sol();
    return 0;
}