#include<bits/stdc++.h>
using namespace std;

int arr[200005];
int prefix[200005]={0},suffix[200005];

void sol()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>arr[i];
    }
    for(int i=2;i<=n-1;++i)
    {
        if(arr[i-1]>=arr[i] and arr[i]>=arr[i+1])
        {
            prefix[i]=prefix[i-1]+1;
            // suffix[i]=suffix[i+1]+1;
            suffix[i]=1;
        }
        else
        {
            prefix[i]=prefix[i-1];
        }
    }
    prefix[n]=prefix[n-1];
    // for(int i=n-1;i>=1;--i)
    // {
    //     if(arr[i+1]>=arr[i] and arr[i]>=arr[i-1])
    //     {
    //         suffix[i]=suffix[i+1]+1;
    //     }
    //     else
    //     {
    //         suffix[i]=suffix[i+1];
    //     }
    // }
    // suffix[1]=suffix[2];
    int left,right;
    for(int i=1;i<=q;++i)
    {
        cin>>left>>right;
        // if(l==r)
        // {
        //     cout<<"0"<<"\n";
        //     continue;
        // }
        // if(l+1==r)
        // {
        //     cout<<"1"<<"\n";
        //     continue;
        // }
        // if(arr[l]>=arr[l+1] and arr[l]>=arr[l-1])
        // {
        //     cout<<r-l+1-max((prefix[r]-prefix[l]),0)<<"\n";
        //     continue;
        // }
        // if(arr[r]>=arr[r+1] and arr[r]>=arr[r-1])
        // {
        //     cout<<r-l+1-max((suffix[l]-suffix[r]),0)<<"\n";
        //     continue;
        // }
        // cout<<r-l+1-max((prefix[r]-prefix[l]),0)-max((suffix[l]-suffix[r]),0)<<"\n";

        if(suffix[right]==1)
        {
            cout<<right-left+1-max<int>((prefix[right]-prefix[left]-1),0)<<"\n";
        }
        else
        {
            cout<<right-left+1-max<<int>((prefix[right]-prefix[left]),0)<<"\n";
        }
    }
}

int main()
{
    sol();
}