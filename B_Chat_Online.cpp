#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	vector<pair<int,int>>vp1,vp2;
	for(int i=0;i<n;++i)
    {
		int x,y;
		cin>>x>>y;
		vp1.emplace_back(x,y);
	}
	for(int i=0;i<m;++i)
    {
		int x,y;
		cin>>x>>y;
		vp2.emplace_back(x,y);
	}
	int ans=0;
	for(int i=l;i<=r;++i)
    {
		for(int j=0;j<m;++j)
        {
			for(int k=0;k<n;++k)
            {
				if((vp2[j].second+i>=vp1[k].first && vp2[j].first+i<=vp1[k].second))
                {
					ans++,j=m;
					break;
				}
			}
		}
	}
	cout<<ans;
}
signed main()
{
	sol();
	return 0;
}