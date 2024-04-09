#include<bits/stdc++.h>
using namespace std;
#define int long long
int ships(int n,int k,vector<int>&durability)
{
    int tot=0;
    for(int i=0;i<n;++i)
    {
        tot+=durability[i];
    }
    if(k>=tot)
    {
        return n;
    }
    int ans=0;
    int f=durability[0];
    int l=durability[n-1];
    while(k>0 && n>0)
    {
        if(f<=l)
        {
            if(f==0)
            {
                ans++;
                n--;
                if(n>0)
                {
                    f=durability[0];
                }
            }
            else
            {
                f--;
            }
            k--;
        }
        else
        {
            if(l==0)
            {
                ans++;
                n--;
                durability.pop_back();
                if(n>0)
                {
                    l=durability[n-1];
                }
            }
            else
            {
                l--;
            }
            k--;
        }
    }
    return ans;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>d(n);
    for(int i=0;i<n;++i)
    {
        cin>>d[i];
    }
    cout<<ships(n,k,d)<<endl;
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