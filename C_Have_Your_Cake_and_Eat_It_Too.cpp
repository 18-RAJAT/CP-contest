#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>a(3,vector<int>(n+1));
    for(int i=0;i<3;++i)
    {
        for(int j=1;j<n+1;++j)
        {
            cin>>a[i][j];
        }
    }
    int sum=0;
    for(int j=1;j<=n;++j)
    {
        sum+=a[0][j];
    }
    //create prefix sum for each row
    vector<vector<int>>prefix(3,vector<int>(n+1));
    for(int i=0;i<3;++i)
    {
        for(int j=1;j<n+1;++j)
        {
            prefix[i][j]=prefix[i][j-1]+a[i][j];
        }
    }
    bool have=false;
    //Calculate the required sum for each sub-array
    int res=sum/3+(sum%3!=0);
    vector<int>ans(6,1);
    vector<vector<int>>combinations=
    {
        {0,1,2},
        {0,2,1},
        {1,0,2},
        {1,2,0},
        {2,0,1},
        {2,1,0}
    };
    auto recur=[&](int index,int l,int r)
    {
        return prefix[index][r]-prefix[index][l-1];
    };
    //Try each permutation of indices
    for(int i=0;i<combinations.size();++i)
    {
        int x=combinations[i][0];
        int y=combinations[i][1];
        int z=combinations[i][2];
        //Iterate through possible split points
        for(int j=1;j<=n-2 && !have;++j)
        {
            if(recur(x,1,j)<res)
            {
                continue;
            }
            auto lb=lower_bound(prefix[y].begin()+j+1,prefix[y].end(),prefix[y][j]+res);
            if(lb==prefix[y].end())
            {
                continue;
            }
            int temp=lb-prefix[y].begin();

            if(recur(z,temp+1,n)>=res)
            {
                have=true;
                ans[x*2]=1;
                ans[x*2+1]=j;
                ans[y*2]=j+1;
                ans[y*2+1]=temp;
                ans[z*2]=temp+1;
                ans[z*2+1]=n;
            }
        }
    }
    if(have)
    {
        for(int i=0;i<ans.size();++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
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