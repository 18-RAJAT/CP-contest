#include<bits/stdc++.h>
using namespace std;

void sol()
{
    auto binarySearch=[&](vector<long long int>&arr,long long int n,long long int key)->long long int
    {
        long long int left=0;
        long long int right=n-1;

        long long int count=0;
        while(left<=right)
        {
            long long int mid=left+(right-left)/2;
            if(arr[mid]<key)
            {
                count=mid+1;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return count;
    };
    long long int n;
    cin>>n;
    vector<long long int>ar,br;
    for(long long int i=0;i<n;++i)
    {
        long long int x;
        cin>>x;
        ar.push_back(x);
    }
    for(long long int i=0;i<n;++i)
    {
        long long int x;
        cin>>x;
        br.push_back(x);
    }
    sort(ar.begin(),ar.end());
    sort(br.begin(),br.end());

    vector<long long int>bs;
    for(long long int i=0;i<n;++i)
    {
        auto vals=binarySearch(br,n,ar[i]);
        bs.push_back(vals);
    }
    long long int f=bs[0];
    for(long long int i=0;i<n-1;++i)
    {
        f*=(bs[i+1]-i-1)%1000000007;
        f%=1000000007;
    }
    cout<<f%1000000007<<"\n";
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}