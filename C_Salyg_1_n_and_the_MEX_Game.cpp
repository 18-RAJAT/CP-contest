#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int>mp;
int n;
int MEX()
{
    for(int i=0;i<=n;++i)
    {
        if(!mp[i])
        {
            return i;
        }
        else
        {
            mp[i]--;
        }
    }
}
void print(int ert)
{
    cout<<ert<<endl;
    cout.flush();
}
void sol()
{
    cin>>n;
    mp.clear();
    vector<int>a(n);
    a.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        mp[a[i]]=1;//set
    }
    print(MEX());
    int x;
    cin>>x;
    while(~x)
    {
        print(x);
        cin>>x;
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