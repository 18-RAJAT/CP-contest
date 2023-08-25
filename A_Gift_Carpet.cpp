#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    char ch[n][m];
    for(int i=0;i<n;++i)
    {
    	for(int j=0;j<m;++j)
    	{
    		cin>>ch[i][j];
    	}
    }
    string s="vika";
    int point=0;
    for(int j=0;j<m;++j)
    {
    	for(int i=0;i<n;++i)
    	{
    		if(ch[i][j]==s[point])
    		{
    			point++;
    			break;
    		}
    	}
    	if(point==4)
    	{
    		break;
    	}
    }
    cout<<(point==4?"YES\n":"NO\n");
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