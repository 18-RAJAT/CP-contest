#include<bits/stdc++.h>
using namespace std;
#define int long long
int prefix[200005][27];
void sol()
{
	int l,r;
	cin>>l>>r;
	int mn=-1;
	for(int i=0;i<27;++i)
	{
		mn=max<int>(mn,prefix[r][i]-prefix[l-1][i]);
	}
	cout<<r-l+1-mn<<endl;
}
signed main()
{
	for(int i=0;i<27;++i)
	{
		prefix[0][i]=0;
	}
	for(int i=1;i<=200005;++i)
	{
		int tmp=i;
		for(int j=0;j<27;++j)
		{
			if(tmp&1)
			{
				prefix[i][j]=prefix[i-1][j]+1;
			}
			else
			{
				prefix[i][j]=prefix[i-1][j];
			}
			tmp/=2;
		}
	}
    int t;
    cin>>t;
    while(t--)
    {
		sol();
    }
    return 0;
}