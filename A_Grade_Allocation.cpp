#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc-->0)
    {
        int n,m;
        cin>>n>>m;
        int arr[n];
        int sum=0;

        for(int i=1;i<=n;++i)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        cout<<min(sum,m)<<"\n";
    }
    return 0;
}