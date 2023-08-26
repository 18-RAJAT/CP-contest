#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
    {
    	cin>>v[i];
    }
    vector<int> a;
    a.push_back(v[0]);
    for(int i=1;i<n;++i)
    {
    	if(v[i]>=v[i-1])
    	{
    		a.push_back(v[i]);
    	}
    	else
    	{
    		a.push_back(1);
    		a.push_back(v[i]);
    	}
    }
    cout<<a.size()<<'\n';
    for(auto& i:a)
    {
    	cout<<i<<" ";
    }
    cout<<"\n";
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