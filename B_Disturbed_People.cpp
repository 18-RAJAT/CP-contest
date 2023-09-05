#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int ans=0,flag=0;
    for(int i=1;i<n-1;++i)
    {
        if(a[i-1] && a[i+1] && !flag && !a[i])
        {
            i++;
            if(i+1<n && a[i+1])
            {
                ans++;
                flag=0;
                // break;
                i++;
            }
            else if(i+1==n)
            {
                ans++;
                flag=0;
                // break;
            }
            else
            {
                flag+=1;
                // break;
            }
        }
        else if(flag)
        {
            ans++;
            flag=0;
        }
    }
    if(flag)
    {
        ans++;
    }
    cout<<ans<<endl;
}