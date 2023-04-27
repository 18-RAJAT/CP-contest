#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sol()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>permute(n);
    for(auto& it:permute)
    {
        cin>>it;
    }
    ll count=0;
    for(int i=0;i<n;++i)
    {
        if(k<=i)
        {
            break;
        }
        unordered_set<ll>possible;
        for(int j=i;j<n;j+=k)
        {
            possible.insert(permute[j]);
        }
        // count+=possible.size();
        for(int j=i;j<n;j+=k)
        {
            // if(not possible.count(permute[j+1]))
            if(not possible.count(j+1))
            {
                // break;
                count++;
            }
            // permute[j]=*possible.begin();
            // possible.erase(possible.begin());
            // count++;
        }
    }
    if(count==0)
    {
        cout<<"0"<<"\n";
        return;
    }
    if(count==1)
    {
        cout<<"1"<<"\n";
        return;
    }
    if(count==2)
    {
        cout<<"1"<<"\n";
        return;
    }
    // if(count==3)
    // {
    //     cout<<"2"<<"\n";
    //     return;
    // }
    cout<<"-1"<<"\n";
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}