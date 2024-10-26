#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>>grid(M);
    unordered_set<int>up,down,right,left;
    for(int i=0;i<M;++i)
    {
        cin>>grid[i].first>>grid[i].second;
        up.insert(grid[i].first);
        down.insert(grid[i].second);
        right.insert(grid[i].first-grid[i].second);
        left.insert(grid[i].first+grid[i].second);
    }
    vector<int>R(up.begin(),up.end());
    vector<int>C(down.begin(),down.end());
    vector<int>U(right.begin(),right.end());
    vector<int>D(left.begin(),left.end());
    int a=R.size()*N,b=C.size()*N,c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0,m=0,n=0,o=0;
    for(auto& it1:U)
    {
        int diff=abs(it1);
        if(diff<N)c+=N-diff;
    }
    int Attack=0;
    for(auto& it1:D)
    {
        if(it1>=2 && it1<=2*N)
        {
            (it1<=N+1)?Attack+=it1-1:Attack+=2*N+1-it1;
        }
    }
    d=Attack,e=(int)R.size()*C.size();
    for(auto& it1:R)
    {
        for(auto& it2:U)
        {
            int ert=it1-it2;
            if(ert>=1 && ert<=N)f++;
        }
    }
    for(auto& it1:R)
    {
        for(auto& it2:D)
        {
            int ert=it2-it1;
            if(ert>=1 && ert<=N)g++;
        }
    }
    for(auto& it1:C)
    {
        for(auto& it2:U)
        {
            int ert=it1+it2;
            if(ert>=1 && ert<=N)h++;
        }
    }
    int over1=0;
    for(auto& it1:C)
    {
        for(auto& it2:D)
        {
            int ert=it2-it1;
            if(ert>=1 && ert<=N)over1++;
        }
    }
    int over2=0;
    for(auto& it1:U)
    {
        for(auto& it2:D)
        {
            if((it1+it2)%2!=0)continue;
            int i=(it1+it2)/2;
            int j=(it2-it1)/2;
            if(i>=1 && i<=N && j>=1 && j<=N)over2++;
        }
    }
    for(auto& it1:R)
    {
        for(auto& it2:C)
        {
            int U=it1-it2;
            if(right.count(U))k++;
        }
    }
    for(auto& it1:R)
    {
        for(auto& it2:C)
        {
            int D=it1+it2;
            if(left.count(D))l++;
        }
    }
    for(auto& it1:R)
    {
        for(auto& it2:U)
        {
            int j=it1-it2;
            int D=2*it1-it2;
            if(j>=1 && j<=N && D>=2 && D<=2*N && left.count(D))m++;
        }
    }
    for(auto& it1:C)
    {
        for(auto& it2:U)
        {
            int i_val=it1+it2;
            int D=2*it1+it2;
            if(i_val>=1 && i_val<=N && D>=2 && D<=2*N && left.count(D))n++;
        }
    }
    for(auto& it1:R)
    {
        for(auto& it2:C)
        {
            int U=it1-it2;
            int D=it1+it2;
            if(right.count(U) && left.count(D))o++;
        }
    }
    //final grid*grid-conditions
    int ans=a+b+c+d-(e+f+g+h+over1+over2)+(k+l+m+n)-o;
    cout<<N*N-ans;
}
signed main()
{
    sol();
    return 0;
}