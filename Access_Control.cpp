#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    auto valid=[&](int x,string s)->bool
    {
        int swipe=0;
        for(auto& it:s)
        {
            if(it=='0')
            {
                swipe--;
                if(swipe<0)
                {
                    return false;
                }
            }
            else
            {
                swipe=x;
            }
        }
        return true;
    };
    cout<<(valid(x,s)?"YES":"NO")<<endl;
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