#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));

    if(n%2==0)
    {
        int count=1;
        for(int j=0;j<m;++j)
        {
            for(int i=0;i<n;++i)
            {
                grid[i][j]=count++;
            }
        }
    }   
    else
    {
        int count=1;
        for(int i=0;i<n;++i)
        grid[i][0]=count++;//start with init.
        for(int j=1;j<m;++j)
        {
            int ok=-1;
            for(int i=0;i<n;++i)
            {
                if(grid[i][j-1]==count-1)
                {
                    ok=i;
                    break;
                }
                // cout<<traversed<<" ";
            }
            grid[ok][j]=count;
            //backtrack
            int movement=count+n-1;
            for(int i=ok-1;i>=0;--i)
            {
                grid[i][j]=movement--;
                // cout<<movement<<" "<<grid[i][j]<<"\n";
            }
            for(int i=ok+1;i<n;++i)
            {
                grid[i][j]=count+(i-ok);
                // ok-=1;
            }
            count+=n;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<grid[i][j]<<" ";cout<<"\n";
        }
    }
    cout<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}