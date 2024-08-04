#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    if(count(a.begin(),a.end(),-1)==n)
    {
        for(int i=0;i<n;++i)a[i]=i&1?2:1;
    }
    else
    {
        int j=-1;
        for(int i=0;i<=n;++i)
        {
            if(~a[i] || i==n)
            {
                if(j==-1)
                {
                    for(int k=i-1;k>=0;--k)
                    {
                        a[k]=a[k+1]==1?2:a[k+1]/2;
                    }
                }
                else if(i==n)
                {
                    for(int k=j+1;k<n;++k)
                    {
                        a[k]=a[k-1]==1?2:a[k-1]/2;
                    }
                }
                else
                {
                    int l=j,r=i;
                    while(l+1<r)
                    {
                        (a[l]>a[r])?(a[l+1]=a[l]/2,l++):(a[r-1]=(a[r]==1?2:a[r]/2),r--);
                    }
                    if((a[l]==1 && a[r]!=2)||(a[l]==2 && a[r]!=1))
                    {
                        cout<<"-1"<<endl;
                        return;
                    }
                }
                j=i;
            }
        }
    }
    for(auto& it:a)cout<<it<<" ";cout<<endl;
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