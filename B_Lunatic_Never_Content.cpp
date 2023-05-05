#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    cin>>n;

    vector<long long int>array(n);
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    long long int ans=0;
    for(int i=0;i<n;++i)
    {
        ans=__gcd<int>(abs(array[n-i-1]-array[i]),ans);
    }
    cout<<ans<<"\n";
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