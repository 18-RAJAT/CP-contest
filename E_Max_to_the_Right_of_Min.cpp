#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
    	int maxpos=a[i];
    	int minpos=a[i];
    	for(int j=i;j<n;j++)
    	{
    		maxpos=max(maxpos,a[j]);
    		minpos=min(minpos,a[j]);
    		if(maxpos>minpos)
    		{
    			ans++;
    		}
    	}
    }
    cout<<ans<<endl;
}
int main()
{
	int t;
	// cin>>t;
	while(t--)
	{
		sol();
    }
}