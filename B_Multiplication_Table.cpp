#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a[n][n];

    long long sum[n];
    memset(sum,0,sizeof(sum));
    vector<long long>ans;

    for(long long i=0;i<n;++i)
    {
        for(long long j=0;j<n;++j)
        {
            cin>>a[i][j];
            if(i<j)
            {
                sum[i]+=a[i][j];
            }
        }
    }
    // function<long long(long long)> pow=[](long long x)->long long
    // {
    //     long long ans(1);
    //     while(x--)
    //     {
    //         ans*=2;
    //     }
    //     return ans;
    // };

    for(long long i=1;i*i<=(sum[n-2]);++i)
    {
        if(sum[n-2]%i==0)
        {
            ans.push_back(i);
            long long tmp=i;
            for(long long j=n-2;j>=0;--j)
            {
                if(sum[j]%tmp==0)
                {
                    ans.push_back(sum[j]/tmp);
                    tmp+=ans.back();
                }
                else
                {
                    ans.clear();
                    break;
                }
            }
            if(ans.size()==n)
            {
                bool ok=true;
                for(long long i=n-1;i>=0;--i)
                {
                    for(long long j=i-1;j>=0;--j)
                    {
                        ok&=a[n-1-i][n-1-j]==ans[i]*ans[j];
                        if(ok==false)
                        {
                            break;
                        }
                    }
                }
                if(ok)
                {
                    for(long long j=n-1;j>=0;--j)
                    {
                        cout<<ans[j]<<" ";
                    }
                    return 0;
                }
                else
                {
                    ans.clear();
                }
            }
            ans.push_back(sum[n-2]/i);
            tmp=ans.back();
            for(long long j=n-2;j>=0;--j)
            {
                if(sum[j]%tmp==0)
                {
                    ans.push_back(sum[j]/tmp);
                    tmp+=ans.back();
                }
                else
                {
                    ans.clear();
                    break;
                }
            }
            if(ans.size()==n)
            {
                bool ok=true;
                for(long long i=n-1;i>=0;--i)
                {
                    for(long long j=i-1;j>=0;--j)
                    {
                        ok&=a[n-1-i][n-1-j]==ans[i]*ans[j];
                        if(ok==false)
                        {
                            break;
                        }
                    }
                }
                if(ok)
                {
                    for(long long j=n-1;j>=0;--j)
                    {
                        cout<<ans[j]<<" ";
                    }
                    return 0;
                }
                else
                {
                    ans.clear();
                }
            }
        }
    }
}