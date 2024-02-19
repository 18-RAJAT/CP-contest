#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='*' && s[i+1]=='*')
        {
            break;
        }
        else
        {
            if(s[i]=='@')
            {
                count++;
            }
        }
    }
    cout<<count<<endl;
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