#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int l,r;
    cin>>l>>r;
    vector<long long int>arr(r);

    arr.resize(r+1);

    for(long long int i=0;i<=r;++i)
    {
        cin>>arr[i];
    }
    long long int ans=0;
    for(long long int i=0;i<17;++i)
    {
        long long int mv1=0,mv2=0;
        for(long long int j=0;j<=r;++j)
        {
            if((arr[j]>>i&1)==0)
            {
                mv1++;
            }
            else
            {
                mv2++;
            }
            // cout<<mv1<<" "<<mv2<<"\n";
        }
        if(mv1<mv2)
        {
            ans|=(1<<i);
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    long long int t;
    cin>>t;
    while(t-->0)
    {
        sol();
    }
    return 0;
}