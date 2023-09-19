#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> mp;
vector<int> v;
int arr[500001];
void fact()
{
    arr[0]=1;
    for(int i=1;i<500001;++i)
    {
        arr[i]=(i*arr[i-1])%1000000007;
    }
}
void prime(map<int,int>&MP)
{
    vector<int>x(500001,1),y(500001,1);
    y[0]=0,y[1]=0;
    for(int i=2;i*i<=500000;++i)
    {
        if(y[i]==1)
        {
            y[i]=1;
            for(int j=2*i;j<=500000;j+=i)
            {
                if(y[j]==1)
                {
                    y[j]=0;
                }
            }
        }
    }
    for(int i=2;i<=500000;++i)
    {
        if(y[i]==1)
        {
            MP[i]++;
        }
    }
}
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    if(n==1)
    {
        cout<<1<<"\n";
        cout<<0<<"\n";
        return;
    }
    // for(int i=2;i*i<=n;++i)
    // {
        //find all the prime factors of n
    //     if(n%i==0)
    //     {
    //         int cnt=0;
    //         while(n%i==0)
    //         {
    //             n/=i;
    //             cnt++;
    //         }
            // cout<<i<<" "<<cnt<<"\n";
    //         mp[i]=cnt;//store the prime factors and their powers
    //         v.push_back(i);
    //     }
    // }
    for(auto&it:mp)
    {
        if(n<it.first)
        {
            break;
        }
        if(n%it.first==0)
        {
            while(n%it.first==0)
            {
                n/=it.first;
                ans++;
            }
            // it.second=cnt;
            v.push_back(it.first);
            // ans++;
        }
    }
    sort(v.begin(),v.end());
    if(n>1)
    {
        // mp[n]=1;
        // v.push_back(n);
        ans++;
        // cout<<"size: "<<v.size()<<"\n";//max 2 prime factors!!
    }
    // if(mp.size()==1)
    if(ans==1)
    {
        cout<<1<<"\n";
        cout<<0<<"\n";
        return;
    }
    // else if(mp.size()==2)
    else if(ans==2)
    {
        cout<<2<<"\n";
    }
    // else if(v.size()==2)
    // {
    //     cout<<2<<"\n";
    //     cout<<v[0]*v[1]<<"\n";
    //     return;
    // }
    // else
    // {
    //     cout<<1<<"\n";
    //     cout<<v[0]*v[0]<<"\n";
    //     return;
    // }
    else
    {
        cout<<1<<"\n";
        if(v.size()>=1)
        {
            cout<<v[0]*v[1]<<"\n";
        }
        else
        {
            cout<<v[0]*v[0]<<"\n";
        }
    }
}
signed main()
{
    fact();
    prime(mp);
    sol();
    return 0;
}