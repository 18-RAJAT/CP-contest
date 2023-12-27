#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n==2)
    {
        cout<<-1<<endl;
        return;
    }
    else if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    vector<vector<int>>matrix(n,vector<int>(n));
    vector<array<int,3>>pairs={{1,2,3},{6,4,5},{8,9,7}};//pairs of 3x3 matrix which are in order
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            matrix[i][j]=pairs[i][j];
        }
    }
    for(int i=4;i<=n;++i)//filling the matrix with pairs of 3x3 matrix
    {
        int position_change=(i-1)*(i-1)+1;
        int index_value=i-1;
        int mat_cnt=0;
        while(mat_cnt<=index_value && index_value>=0)
        {
            matrix[mat_cnt][index_value]=position_change;
            position_change++;
            mat_cnt++;
            // cout<<mat_cnt<<" "<<index_value<<endl;
        }
        mat_cnt=i-1;
        index_value=mat_cnt-1;
        while(index_value>=0)
        {
            matrix[mat_cnt][index_value]=position_change;
            position_change++;
            // cout<<mat_cnt<<" "<<index_value<<endl;
            // mat_cnt++;
            index_value--;
        }
    }
    // assert(matrix[n-1][n-1]==n*n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<matrix[i][j]<<" ";
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