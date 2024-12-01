#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int t;
    cin>>t;
    array<int,4>Rows={-1,1,0,0},Cols={0,0,-1,1};
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<string>s(n);
        for(int i=0;i<n;++i)cin>>s[i];
        int N=n*m;
        vector<vector<int>>Arr(N),Brr(N);
        vector<int>Temp(N,0);
        for(int r=0;r<n;++r)
        {
            for(int c=0;c<m;++c)
            {
                char ch=s[r][c];
                if(ch=='U' || ch=='D' || ch=='L' || ch=='R')
                {
                    int x;
                    if(ch=='U')x=0;
                    else if(ch=='D')x=1;
                    else if(ch=='L')x=2;
                    else x=3;
                    int R=r+Rows[x],C=c+Cols[x];
                    if(R>=0 && R<n && C>=0 && C<m)
                    {
                        Arr[R*m+C].push_back(r*m+c);
                    }
                }
                else
                {
                    int res=0;
                    for(int p=0;p<4;++p)
                    {
                        int R=r+Rows[p],C=c+Cols[p];
                        if(R>=0 && R<n && C>=0 && C<m)
                        {
                            Brr[R*m+C].push_back(r*m+c);
                            res++;
                        }
                    }
                    Temp[r*m+c]=move(res);
                }
            }
        }
        vector<int>Trap(N,1);
        queue<int>q;
        for(int r=0;r<n;++r)
        {
            for(int c=0;c<m;++c)
            {
                char ch=s[r][c];
                auto valid=[&]()->void
                {
                    if(ch=='U' || ch=='D' || ch=='L' || ch=='R')
                    {
                        int x;
                        if(ch=='U')x=0;
                        else if(ch=='D')x=1;
                        else if(ch=='L')x=2;
                        else x=3;
                        int R=r+Rows[x],C=c+Cols[x];
                        if(R<0 || R>=n || C<0 || C>=m)q.push(r*m+c);
                    }
                };
                valid();
            }
        }
        for(int i=0;i<N;++i)
        {
            int div=i/m,M=i%m;
            if(s[div][M]=='?')
            {
                if(Temp[i]==0)q.push(i);
            }
        }
        while(!q.empty())
        {
            int Tp=q.front();
            q.pop();
            if(!Trap[Tp])continue;
            Trap[Tp]=0;
            for(auto& it:Arr[Tp])
            {
                if(Trap[it])q.push(it);
            }
            for(auto& it:Brr[Tp])
            {
                if(Trap[it])
                {
                    Temp[it]--;
                    if(Temp[it]==0)
                    {
                        q.push(it);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<N;++i)
        {
            if(Trap[i])
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}