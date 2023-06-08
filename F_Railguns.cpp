#include<bits/stdc++.h>
using namespace std;

long long DX[3]={0,1,0};
long long DY[3]={1,0,0};
long long n,m;
void sol()
{
    cin>>n>>m;
    map<long long,map<long long,long long>>*mp1=new map<long long,map<long long,long long>>();
    map<long long,map<long long,long long>>*mp2=new map<long long,map<long long,long long>>();

    long long k;
    cin>>k;
    while(k-->0)
    {
        long long x,dict,pos;
        cin>>x>>dict>>pos;

        if(1e9<=x)
        {
            continue;
        }
        if(dict==1)
        {
            (*mp1)[x][pos]++;
        }
        else
        {
            (*mp2)[x][pos]++;
        }
    }
    queue<tuple<long long,long long,long long>>que;
    que.push(make_tuple(0,0,0));

    while(not que.empty())
    {
        auto front=que.front();
        long long x=get<0>(front);
        long long y=get<1>(front);
        long long z=get<2>(front);

        que.pop();

        for(long long i=0;i<3;++i)
        {
            long long xx=x+DX[i];
            long long yy=y+DY[i];

            long long move=z+1;

            if(1e9<=move)
            {
                continue;
            }
            if(n<xx or m<yy)
            {
                continue;
            }
            // if(xx==0 and yy==0)
            // {
            //     continue;
            // }
            if((*mp1)[move].count(xx) or (*mp2)[move].count(yy))
            {
                continue;
            }
            if(xx==n and yy==m)
            {
                cout<<move<<"\n";
                delete mp1;
                delete mp2;
                return;
            }
            que.push(make_tuple(xx,yy,move));
        }
    }
    cout<<"-1"<<"\n";
    delete mp1;
    delete mp2;
}
int main()
{
    long long t;
    cin>>t;
    while(t-->0)
    {
        sol();
    }
    return (0-0);
}