#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,q;
    cin>>n>>a>>q;
    string s;
    cin>>s;
    int maxi=a,ok=a,sum=a;
    for(int i=0;i<q;++i)
    {
        if(s[i]=='+')
        {
            sum++,ok++;
            maxi=max(maxi,ok);
        }
        else
        {
            ok--;
            // maxi=max(maxi,ok);
        }
    }
    if(n==maxi)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<((sum<n)?"NO\n":"MAYBE\n");
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