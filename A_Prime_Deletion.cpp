#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            cout<<13<<endl;
            break;
        }
        else if(s[i]=='3')
        {
            cout<<31<<endl;
            break;
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