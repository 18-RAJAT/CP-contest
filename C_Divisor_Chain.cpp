#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>ans;
    int x=1,y;
    while(x<=n)
    {
        ans.push_back(x);
        x<<=1;
    }
    x>>=1;
    y=x;
    x>>=1;
    while(x)
    {
        if(n&x)
        {
            y+=x;
            ans.push_back(y);
        }
        x>>=1;
    }   
    n=ans.size();
    cout<<ans.size()<<endl;
    while(n--)  
    {
        cout<<ans[n]<<" ";
    }
    // cout<<x<<" "<<y<<" "<<endl;
    cout<<endl;
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