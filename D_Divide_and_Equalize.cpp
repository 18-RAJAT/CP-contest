#include<bits/stdc++.h>
using namespace std;
#define int long long
int square(int x)
{
    return x*x;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    bool flag=true;//if all the elements are equal
    for(auto& it:a)
    {
        int tmp=it;//for each element
        for(int i=2;i<=sqrt(tmp);++i)
        {
            //getting the prime factors
            while(tmp%i==0)
            {
                tmp/=i;
                mp[i]++;
            }
        }
        if(tmp!=1)
        {
            mp[tmp]++;
        }
        // else
        // {
        //     flag=false;
        // }
    }
    for(auto& it:mp)
    {
        if(it.second%n!=0)// || ~it.second&1)
        {
            flag=false;
        }
    }
    cout<<(flag?"YES":"NO")<<endl;
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