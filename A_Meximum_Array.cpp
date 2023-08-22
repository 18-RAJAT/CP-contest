#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    multiset<int>ms;
    for(int i=0;i<n;++i)
    {
        ms.insert(a[i]);
    }
    if(n==1)
    {
        if(a[0]==0)
        {
            cout<<"1\n";
            cout<<"1\n";
            return;
        }
        else
        {
            cout<<"1\n";
            cout<<"0\n";
        }
        return;
    }
    int ert=0;
    int cur=-1;
    int r=-1;
    vector<int>vec;
    unordered_map<int,int>mp;
    mp.erase(mp.begin(),mp.end());
    for(int i=0;i<n;++i)
    {
        mp[a[i]]++;
        ms.erase(ms.find(a[i]));
        if(a[i]==ert)
        {
            while(mp[ert]>0)ert++;
            if(ms.find(ert)==ms.end())
            {
                vec.push_back(ert);
                ert=0;
                r=i;
                mp.clear();
            }
        }
    }
    for(int i=r+1;i<n;++i)
    {
        vec.push_back(0);
    }
    cout<<vec.size()<<"\n";
    for(auto it:vec)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}