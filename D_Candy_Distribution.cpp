#include <bits/stdc++.h>
using namespace std;
#define int long long

void recur(int n,vector<int>& arr,int k)
{
    for(int i=0;i<k;++i)
    {
        vector<int>temp=arr;
        for(int i=0;i<n-1;++i)
        {
            if(arr[i]>=1)
            {
                temp[i]--; 
                temp[i+1]++;
            }
        }
        arr=move(temp); 
    }
}
void sol()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    recur(n,arr,k);
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