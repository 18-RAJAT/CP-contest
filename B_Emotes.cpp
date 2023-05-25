#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,m,k;
    cin>>n>>m>>k;

    vector<long long int>arr(n,0);

    for(auto&it:arr)
    {
        cin>>it;
    }
    sort(arr.rbegin(),arr.rend());
    long long int ans=m/(k+1)*(arr[0]*k+arr[1])+m%(k+1)*arr[0];

    cout<<ans<<"\n";
}