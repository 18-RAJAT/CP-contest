#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int>s[100005];
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    multiset<int>ms;
    for(int i=0;i<n-1;++i)
    {
        if(s[i]=='4' && s[i+1]=='7')
        {
            ms.insert(i+1);
        }
    }
    while(ms.size()>0 && k>0)
    {
        int x=*ms.begin();
        if(x&1)
        {
            s[x-1]='4';
            s[x]='4';
            ms.erase(ms.find(x));
            k--;
            if(x+1<n && s[x+1]=='7')
            {
                if(k&1)
                {
                    s[x]='7';
                    break;
                }
                else
                {
                    s[x]='4';
                    break;
                }
            }
        }
        else
        {
            s[x-1]='7';
            s[x]='7';
            ms.erase(ms.find(x));
            k--;
            if(x-2>=0 && s[x-2]=='4')
            {
                if(k&1)
                {
                    s[x-1]='4';
                    break;
                }
                else
                {
                    s[x-1]='7';
                    break;
                }
            }
        }
    }
    cout<<s;
}
signed main()
{
    sol();
    return 0;
}