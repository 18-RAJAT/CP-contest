#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    int a[n];
    for(auto&it:a)
    {
        cin>>it;
    }
    if(a[0]<a[1])
    {
        cout<<"NO";
        return 0;
    }
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        if(a[i]==100)
        {
            if(mp.find(50)!=mp.end() && mp[50]>0)
            {
                mp[50]--;
                if(mp.find(25)!=mp.end() && mp[25]>0)
                {
                    mp[25]--;
                }
                else
                {
                    cout<<"NO";
                    return 0;
                }
            }
            else if(mp.find(25)!=mp.end() && mp[25]>=3)
            {
                mp[25]-=3;
            }
            else if(mp.find(25)!=mp.end() && mp[25]>0 && mp.find(50)==mp.end())
            {
                mp[25]--;
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
        else if(a[i]==50)
        {
            if(mp.find(25)!=mp.end() && mp[25]>0)
            {
                mp[25]--;
            }
            else
            {
                cout<<"NO";
                return 0;
            }
            mp[50]++;
        }
        else
        {
            mp[25]++;
        }
    }
    cout<<"YES";
}