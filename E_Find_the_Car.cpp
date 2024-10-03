#include<bits/stdc++.h>
using namespace std;
#define int long long
int CustomLowerBound(vector<int>&a,int x)
{
    int low=0,high=a.size();
    while(low<high)
    {
        int mid=(low+high)/2;
        (a[mid]<x)?low=mid+1:high=mid;
    }
    return low;
}
void sol()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>a(k);
    for(int i=0;i<k;++i)cin>>a[i];
    vector<int>b(k);
    for(int i=0;i<k;++i)cin>>b[i];
    for(int i=0;i<q;++i)
    {
        int x;
        cin>>x;
        int index=CustomLowerBound(a,x);
        index--;
        if(index==-1)
        {
            int distance=a[0],time=b[0];
            cout<<(x*time)/distance<<" ";
        }
        else
        {
            int distance=a[index+1]-a[index],time=b[index+1]-b[index];
            cout<<(x-a[index])*time/distance+b[index]<<" ";
        }
    }
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
