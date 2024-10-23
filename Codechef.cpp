#include <bits/stdc++.h>
using namespace std;
#define int long long

int sol(const vector<int>&a,int m,vector<int>&count)
{
    vector<bool>div(m+2,false);
    for(auto& it:a)
    {
        for(int d=1;d*d<=it;++d)
        {
            if(it%d==0)
            {
                if(d<=m)
                {
                    div[d]=true;
                    count[d]++;
                }
                if(it/d<=m&&d!=it/d)
                {
                    div[it/d]=true;
                    count[it/d]++;
                }
            }
        }
    }
    for(int mex=1;mex<=m+1;++mex)
    {
        if(!div[mex])return mex;
    }
    return m+1;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        vector<int>count(m+1,0);
        int init=sol(a,m,count);
        int MEX=init;
        for(int i=0;i<n;++i)
        {
            int tmp=a[i];
            for(int x=1;x<=m;++x)
            {
                if(x!=tmp)
                {
                    for(int d=1;d*d<=tmp;++d)
                    {
                        if(tmp%d==0)
                        {
                            if(d<=m)count[d]--;
                            if(tmp/d<=m && d!=tmp/d)count[tmp/d]--;
                        }
                    }
                    for(int d=1;d*d<=x;++d)
                    {
                        if(x%d==0)
                        {
                            if(d<=m)count[d]++;
                            if(x/d<=m && d!=x/d)count[x/d]++;
                        }
                    }
                    int NewMEX=init;
                    while(NewMEX<=m && count[NewMEX]>=1)
                    {
                        NewMEX++;
                    }
                    MEX=max(MEX,NewMEX);
                    for(int d=1;d*d<=x;++d)
                    {
                        if(x%d==0)
                        {
                            if(d<=m)count[d]--;
                            if(x/d<=m && d!=x/d)count[x/d]--;
                        }
                    }
                    for(int d=1;d*d<=tmp;++d)
                    {
                        if(tmp%d==0)
                        {
                            if(d<=m)count[d]++;
                            if(tmp/d<=m && d!=tmp/d)count[tmp/d]++;
                        }
                    }
                }
            }
        }
        cout<<MEX<<endl;
    }
    return 0;
}