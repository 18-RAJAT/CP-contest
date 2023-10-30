#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& it:a)
    {
        cin>>it;
    }
    sort(a.begin(),a.end());
    int i=0,j=n-1;
    int count=0;
    int ans=0;
    while(i<=j)
    {
        if(i==j)//last monster
        {
            // int x=(a[i]-count+1)/2;
            // ans+=min(a[i],max(1LL,x)/2+1);
            int maxi=max(1LL,(a[i]-count+1)/2+1);//maxi is the number of monsters
            int mini=min(a[i],maxi);//mini is the number of monsters
            ans+=mini;
            break;
        }
        count+=a[i];//count is the number of monsters
        ans+=a[i];//here ans??????
        i++;
        if(a[j]<=count)
        {
            count-=a[j];
            j--;
            // if(i<=j)
            // {
            //     ans+=a[j];
            // }
            ans++;
        }
        if(i==j+1)
        {
            if(count>1)
            {
                int half=count/2;//monster count
                ans-=half-1;
            }
        }
    }
    cout<<ans<<"\n";
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