#include<bits/stdc++.h>
using namespace std;
#define int long long
int MinSwap(vector<int>& a)
{
    int n=a.size();
    vector<int>visited(n,0);
    int swaps=0;
    for(int i=0;i<n;++i)
    {
        if(!visited[i])
        {
            int detect=0,x=i;
            while(!visited[x])
            {
                visited[x]=1,x=a[x]-1,detect++;
            }
            if(detect>=3)swaps+=(detect-1)/2;
        }
    }
    return swaps;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    cout<<MinSwap(a)<<endl;
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