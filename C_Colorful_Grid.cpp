#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    int lines=n+m;
    if(k<lines-2 || k%2!=(lines%2))
    {
        cout<<"NO"<<endl;
        return;
    }

    vector<vector<char>>color_R(n,vector<char>(m-1,'B'));
    vector<vector<char>>color_B(n-1,vector<char>(m,'R'));
    string colors="RB";
    int current=0;
    for(int j=0;j+1<m;++j)
    {
        color_R[0][j]=colors[current];
        current^=1;//0->1,1->0
    }
    for(int i=0;i+1<n;++i)
    {
        color_B[i][m-1]=colors[current];
        current^=1;//0->1,1->0
    }
    cout<<"YES"<<endl;
    for(auto& R:color_R)
    {
        for(auto& it:R)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    for(auto& B:color_B)
    {
        for(auto& it:B)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
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