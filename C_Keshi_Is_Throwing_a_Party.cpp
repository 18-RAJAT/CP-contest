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
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;++i)
        {
            cin>>v[i].first>>v[i].second;
        }
        int low=1,high=n,ans=1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int pos=0;
            for(int i=0;i<n;++i)
            {
                if(v[i].second>=pos && mid-1-pos<=v[i].first)
                {
                    pos++;
                }
            }
            if(pos>=mid)
            {
                low=mid+1;
                ans=max<int>(ans,mid);
            }
            else
            {
                high=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
}