#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n,0);
        arr.resize(n+1,0);
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>arr[i];
        }
        for(int i=1;i<=n;++i)
        {       
            if(arr[i]<0)
            {
                break;
            }
            ans+=arr[i];
        }
        cout<<ans<<"\n";
    }
}