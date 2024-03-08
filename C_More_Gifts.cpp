#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{\
    int n,k,t;
    cin>>n>>k>>t;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(arr[i]>t)
        {
            ans+=arr[i]/t;
            if(arr[i]%t!=0)
            {
                ans++;
            }
        }
        else
        {
            ans++;
        }
    }
    if(ans<5)
    {
        cout<<(n*ans)+n<<endl;
        return;
    }
    else 
    {
        cout<<((ans/2)*k)+1<<endl;
        return;
    }
    assert(false);
}
signed main()
{
    sol();
    return 0;
}