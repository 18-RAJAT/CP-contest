#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n,q,m;
    cin>>n>>q>>m;
    long long int a[n],b[n],c[n];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        c[i]=b[i];
    }
    long long int d[m],e[m];
    memset(d,0,sizeof(d));
    memset(e,0,sizeof(e));
    for(int i=0;i<m;i++)
    {
        cin>>d[i]>>e[i];
    }
    long long int f[q],g[q];
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    for(int i=0;i<q;i++)
    {
        cin>>f[i]>>g[i];
    }
    long long int h[m];
    memset(h,0,sizeof(h));
    for(int i=0;i<m;i++)
    {
        h[i]=0;
    }
    long long int j=0;
    for(int i=0;i<q;i++)
    {
        long long int k=0;
        for(int l=0;l<n;l++)
        {
            if(f[i]==a[l])
            {
                k=1;
                break;
            }
        }
        if(k==1)
        {
            cout<<f[i]<<"\n";
            for(int l=0;l<n;l++)
            {
                if(f[i]==a[l])
                {
                    b[l]=g[i];
                    break;
                }
            }
        }
        else
        {
            long long int l=0;
            for(int m=0;m<n;m++)
            {
                if(b[m]==0)
                {
                    l=1;
                    break;
                }
            }
            if(l==1)
            {
                cout<<n+1<<"\n";
                cout<<flush;
                for(int m=0;m<n;m++)
                {
                    if(b[m]==0)
                    {
                        a[m]=f[i];
                        b[m]=g[i];
                        break;
                    }
                }
            }
            else
            {
                long long int m=0;
                for(int n=0;n<n;n++)
                {
                    if(b[n]==c[n])
                    {
                        m=1;
                        break;
                    }
                }
                if(m==1)
                {
                    cout<<2<<"\n";
                    cout<<flush;
                    for(int n=0;n<n;n++)
                    {
                        if(b[n]==c[n])
                        {
                            a[n]=f[i];
                            b[n]=g[i];
                            break;
                        }
                    }
                }
                else
                {
                    long long int n=0;
                    for(int o=0;o<n;o++)
                    {
                        if(b[o]==d[j])
                        {
                            n=1;
                            break;
                        }
                    }
                    if(n==1)
                    {
                        cout<<1<<"\n";
                        cout<<flush;
                        for(int o=0;o<n;o++)
                        {
                            if(b[o]==d[j])
                            {
                                a[o]=f[i];
                                b[o]=g[i];
                                break;
                            }
                        }
                    }
                    else
                    {
                        long long int o=0;
                        for(int p=0;p<n;p++)
                        {
                            if(b[p]==e[j])
                            {
                                o=1;
                                break;
                            }
                        }
                        if(o==1 and h[j]==0)
                        {
                            cout<<e[j]<<"\n";
                            h[j]=1;
                            cout<<flush;
                            for(int p=0;p<n;p++)
                            {
                                if(b[p]==e[j])
                                {
                                    a[p]=f[i];
                                    b[p]=g[i];
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout<<g[i]<<"\n";
                            cout<<flush;
                            for(int p=0;p<n;p++)
                            {
                                if(b[p]==d[j])
                                {
                                    a[p]=f[i];
                                    b[p]=g[i];
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        j++;
        if(j==m)
        {
            j=0;
        }
    }
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}
