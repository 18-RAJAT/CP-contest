#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;++i)
    {
    	cin>>a[i];
    }
    if(a[0][0]=='1')
    {
    	cout<<"-1\n";
    	return;
    }
    vector<array<int,4>>ans;
    for(int i=0;i<n;++i)
    {
    	for(int j=0;j<m;++j)
    	{
    		if(a[i][j]=='0')
            {
                continue;
            }
    		if(i>0)
            {
                ans.push_back({i-1,j,i,j});
            }
    		else
            {
                ans.push_back({i,j-1,i,j});
            }
    	}
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(auto &[x1,y1,x2,y2]:ans)
    {
    	x1++,y1++,x2++,y2++;
    	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
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