#include<bits/stdc++.h>
using namespace std;

vector<int>buildTree[10001];
int n,sza[10001],ans=0;

int inverse(int a,int b=1000000007)
{
    return(1<a?b-inverse(b%a,a)*b/a:1);
}

int dfs(int x,int y)
{
    // sza[x]=sza[y]+1;
    sza[x]=1;
    // for(int i=0;i<buildTree[x].size();++i)
    // {
    //     int z=buildTree[x][i];
    //     if(z==y)
    //     {
    //         continue;
    //     }
    //     sza[x]+=dfs(z,x);
    // }
    for(auto it:buildTree[x])
    {
        if(it-y)
        {
            sza[x]+=dfs(it,x);
        }
        ans+=sza[x]*(n-sza[x]);
    }
    return sza[x];
}
int main()
{
    cin>>n;
    int m;
    cin>>m;
    if(m!=2)
    {
        cout<<"1"<<"\n";
        return 0;
    }
    for(int i=1;i<n;++i)
    {
        int src,dest;
        cin>>src>>dest;
        buildTree[src].push_back(dest);
        buildTree[dest].push_back(src);
    }
    int init1,init2;
    init1=init2=1;

    dfs(init1,init2);

    int res=inverse(n*(n-1)/2+1);
    cout<<abs(ans*res)%1000000007<<"\n";
}