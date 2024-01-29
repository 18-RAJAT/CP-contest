#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>arr;
bool isPrime(int n)
{
    if(n<=1 || (n>2 && n%2==0) || (n>3 && n%3==0))
    {
        return false;
    }
    else if(n<=3)
    {
        return true;
    }
    auto check=[&](int n)->bool
    {
        for(int i=5;i*i<=n;i+=6)
        {
            if(n%i==0 || n%(i+2)==0)//i+2 is always divisible by 6 so no need to check for it
            {
                return false;
            }
        }
        return true;
    };
    return check(n);
}
void sol()
{
    int n;
    cin>>n;
    int a[n];
    map<int,int>mp,select;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    map<int,vector<int>>mp1;
    for(auto& it:arr)
    {
        for(int i=0;i<n;++i)
        {
            if(a[i]%it==0 && mp[a[i]]>=1)
            {
                mp[a[i]]--;
                select[a[i]]=1;
                mp1[it].push_back(i);
            }
        }
    }
    cout<<mp1.size()<<endl;
    int count=1;
    int ans[n];
    for(auto& it:mp1)
    {
        vector<int>temp=it.second;
        for(auto& it1:temp)
        {
            ans[it1]=count;
        }
        count++;
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
signed main()
{
    int t;
    cin>>t;
    for(int i=2;i<=100;++i)
    {
        if(isPrime(i))
        {
            arr.push_back(i);
        }
    }
    while(t--)
    {
        sol();
    }
    return 0;
}