#include<bits/stdc++.h>
using namespace std;

int arr[200001];
int prefix[200001];
int suffix[200001];
void sol()
{
    int n,q;
    cin>>n>>q;
    // vector<int>arr(200001);
    // memset(arr,0,sizeof(arr));

    for(int i=1;i<=n;++i)
    {
        cin>>arr[i];
    }
    // int countLongestIncSubs=0;
    // vector<int>prefix(200001,0);
    // vector<int>suffix(200001);
    memset(prefix,0,sizeof(prefix));

    // prefix[1]=1,prefix[2]=2;
    for(int i=2;i<=n-1;++i)
    {
        // prefix[i]=prefix[i-1];
        // if(arr[i]>arr[i-1])
        // {
        //     prefix[i]=prefix[i-1]+1;
        // }
        // if(not (arr[i-1]<arr[i] and arr[i]<arr[i+1]))

        // if(not(arr[i-2]>=arr[i-1] and arr[i-1]>=arr[i]))
        // {
        //     // countLongestIncSubs+=1;
        //     prefix[i]+=1;
        // }
        if(arr[i]<=arr[i-1] and arr[i+1]<=arr[i])
        {
            prefix[i]=prefix[i-1]+1;
            suffix[i]=1;
        }
        else
        {
            prefix[i]=prefix[i-1];
        }
        // else
        // {
        //     prefix[i]=2;
        // }
    }
    prefix[n]=prefix[n-1];
    int left,right;
    // while(q--)
    for(int i=1;i<=q;++i)
    {
        cin>>left>>right;
        // if(right-left+1<3)
        // {
        //     cout<<right-left+1<<"\n";
        //     // continue;
        // }
        if(suffix[right]==1)
        {
            // int maximum=max<int>(prefix[right]-prefix[right]-1,0);
            // cout<<right-left+1-maximum<<"\n";
            cout<<right-left+1-max((prefix[right]-prefix[right-1]),0)<<"\n";
        }
        // int ans=prefix[right]-prefix[left];
        // cout<<ans<<"\n";
        else
        {
            // int ans=prefix[right]-prefix[left-1];
            // if(left>=3)
            // {
            //     if(arr[left-2]>=arr[left-1] and arr[left-1]>=arr[left])
            //     {
            //         // ans-=1;
            //         ans+=1;
            //     }
            // }
            // if(left>=2)
            // {
            //     if(arr[left-1]>=arr[left] and arr[left]>=arr[left+1])
            //     {
            //         // ans-=1;
            //         ans+=1;
            //     }
            // }
            // cout<<ans<<"\n";
            // int maximum=max<int>(prefix[right]-prefix[left],0);
            // cout<<right-left+1-maximum<<"\n";
            cout<<right-left+1-max((prefix[right]-prefix[left]),0)<<"\n";
        }
        // cout<<ans<<"\n";
    }
}
int main()
{
    int testCases;
    // cin>>testCases;
    while(testCases--)
    {
        sol();
    }
}