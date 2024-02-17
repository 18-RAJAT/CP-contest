#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[300005];
int arr[300005];
int func(int index,int k,int current)
{
    if(k==0)
    {
        return 0;
    }
    int &res=dp[index];
    if(~res)
    {
        return res;
    }
    if(arr[index]==0 && k>=1)
    {
        res=max(1+func(index+1,k,1),current+func(index+1,k-1,current+1));
    }
    else
    {
        res=current+func(index+1,k-1,current+1);
    }
    return res;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int ans=0;
    int first=0,second=0;
    for(int i=0,cnt=0;i<n;++i,cnt=0)//cnt is number of zeros in the current window
    {
        if(arr[i]==0)
        {
            cnt++;
        }
        // int j=i+1;
        int j=i;
        while(j<n && cnt<k)
        {
            if(arr[j]==0)
            {
                cnt++;
            }
            j++;
        }
        while(j<n)
        {
            if(arr[j]==1)
            {
                j++;
            }
            else
            {
                break;
            }
        }
        if(abs(j-i)>ans)
        {
            ans=j-i,first=i,second=j;
        }
    }
    for(int i=first;i<second;++i)
    {
        arr[i]=1;
    }
    cout<<ans<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}