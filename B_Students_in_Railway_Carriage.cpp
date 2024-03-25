#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int temp=a+b;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='*')continue;
        if(a<b)swap(a,b);
        for(int j=0;s[i]=='.' && i<n;++j)
        {
            if(j%2==0)
            {
                if(a>=1 && (i==0 || s[i-1]=='B' || s[i-1]=='*' || s[i-1]=='.' || s[i-2]=='A'))
                {
                    s[i]='A';
                    a--;
                }
            }
            else
            {
                if(b>=1 && (i==0 || s[i-1]=='A' || s[i-1]=='*' || s[i-1]=='.' || s[i-2]=='B'))
                {
                    s[i]='B';
                    b--;
                }
            }
            i++;
        }
    }
    cout<<temp-a-b<<endl;
}
signed main()
{
    sol();
    return 0;
}