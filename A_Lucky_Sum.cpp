#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>lucky;
void generate(int x=0,int length=0)
{
    if(length>0 && x!=0)
    {
        lucky.push_back(x);
    }
    if(length>=12)
    {
        return;
    }
    generate(x*10+4,length+1);
    generate(x*10+7,length+1);
}
void sol()
{
    generate();
    sort(lucky.begin(),lucky.end());
    int l,r;
    cin>>l>>r;
    int Ans=0;
    for(auto it=lucky.begin();it!=lucky.end();++it)
    {
        if(*it>=l)
        {
            if(*it<=r)
            {
                Ans+=(*it-l+1)*(*it);
                l=*it+1;
            }
            else
            {
                Ans+=(r-l+1)*(*it);
                break;
            }
        }
    }
    cout<<Ans;
}
signed main()
{
    sol();
    return 0;
}