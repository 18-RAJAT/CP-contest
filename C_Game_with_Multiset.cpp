#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>frequency(32);
    while(n--)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            int x;
            cin>>x;
            frequency[x]++;
        }
        else
        {
            int y;
            cin>>y;
            int ok=1;
            function<int(int,int)> right_shift=[&](int p,int q)->int
            {
                return p>>q;
            };
            vector<int>ans=frequency;
            for(int i=0;i<30;++i)
            {
                if((right_shift(y,i))&1)
                {
                    ans[i]?ans[i]--:ok=0;
                }
                ans[i+1]+=ans[i]/2;//carry
            }
            cout<<(ok?"YES":"NO")<<endl;
        }
    }
}
signed main()
{
    sol();
    return 0;
}