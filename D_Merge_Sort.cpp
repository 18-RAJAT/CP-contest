#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],n,k;
void bottom_up_merge_sort(int& n,int &k)
{
    for(int i=1;i<n;i=2*i)
    {
        for(int j=0;j<n;j=j+2*i)
        {
            int index1=i,index2=min(j+2*i,n);
            int mid=min(i+j,n);
            if(k>=2)k-=2;
            else
            {
                sort(a+index1,a+index2);
                mid--;
            }
        }
    }
}
void sol()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)a[i]=n-i;
    k--;
    bottom_up_merge_sort(n,k);
    if(k>=1)
    {
        cout<<-1;
        return;
    }
    if(n%2==0)sort(a,a+n);
    for(int i=0;i<n;++i)cout<<a[i]<<" ";
}
signed main()
{
    sol();
    return 0;
}