#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<bool>>subMatrix(n,vector<bool>(m));
    vector<vector<int>>R(n,vector<int>(m));
    vector<vector<int>>C(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        int tmp=m;
        for(int j=m-1;j>=0;--j)
        {
            if(v[i][j]==1)
            {
                R[i][j]=tmp-j;
            }
            else
            {
                tmp=j;
            }
            // cout<<"test"<<tmp<<endl;
        }
    }
    for(int j=0;j<m;++j)
    {
        int tmp=n;
        for(int i=n-1;i>=0;--i)
        {
            if(v[i][j]==1)
            {
                C[i][j]=tmp-i;
            }
            else
            {
                tmp=i;
            }
            // cout<<"test"<<tmp<<endl;
        }
    }
    vector<pair<int,int>>ans;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(C[i][j]<=1 || R[i][j]<=1)
            {
                continue;
            }
            else if(v[i+1][j+1]==0)
            {
                continue;
            }
            else if(v[i+1][j]==0)
            {
                continue;
            }
            else if(v[i][j+1]==0)
            {
                continue;
            }
            else if(v[i][j]==0)
            {
                continue;
            }
            ans.emplace_back(i+1,j+1);
            subMatrix[i][j]=true;
            subMatrix[i+1][j]=true;
            subMatrix[i][j+1]=true;
            subMatrix[i+1][j+1]=true;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(v[i][j]==1 && !subMatrix[i][j])
            {
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}