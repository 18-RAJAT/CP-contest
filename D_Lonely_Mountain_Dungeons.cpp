#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,b,x;
    cin>>n>>b>>x;
    int array[n];
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    function<int(int,int)>get=[&](int n,int k)->int
    {
        int x=n/k,y=n%k;
        int c1=y,c2=k-y;
        int ans=c1*(x+1)*(n-x-1)+c2*x*(n-x);
        return ans/2;
    };
    sort(array,array+n);
    int mx=*max_element(array,array+n);
    int ans=0;
    int arr[n];
    fill(arr,arr+n,0);
    int cur=0;
    int l=0;
    for(int i=1;i<=mx;++i)
    {
        while(l<n && array[l]<i)
        {
            l++;
        }
        for(int j=l;j<n;++j)
        {
            cur-=b*arr[j];
            arr[j]=max(arr[j],get(array[j],i));
            cur+=b*arr[j];
        }
        ans=max(ans,cur);
        cur-=x;
    }
    cout<<ans<<endl;
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