#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        int mx=0;
        for(int i=0;i<n;++i)
        {
            // int x;
            // cin>>x;
            // a.push_back(x);
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        if((mx-1)*n<k)
        {
            cout<<-1<<"\n";
        }
        else
        {
            int ans=-1;
            while(k)
            {
                ans=-1;
                for(int i=0;i<n-1;++i)
                {
                    if(a[i]<a[i+1])
                    {
                        ans=i;
                        k--;a[i]++;
                        break;
                    }
                }
                if(ans!=-1)
                {
                    break;
                }
            }
            if(ans==-1)
            {
                ans+=1;
                cout<<ans<<"\n";
            }
        }
    }
}