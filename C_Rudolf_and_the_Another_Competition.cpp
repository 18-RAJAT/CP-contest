#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long n,m,h;
    cin>>n>>m>>h;
    vector<vector<long long>>a(n,vector<long long>(m));
    vector<pair<long long,long long>>vals;
    pair<long long,long long>pr;
    for(long long i=0;i<n;++i)
    {
        for(long long j=0;j<m;++j)
        {
            cin>>a[i][j];
        }
        sort(a[i].begin(),a[i].end());
        long long cnt=0,penalty=0;
        long long tt=0;
        for(auto& it:a[i])
        {
            if(tt+it<=h)
            {
                cnt++;
                tt+=it;
                penalty+=tt;
            }
        }
        vals.push_back({-cnt,penalty});
        if(i==0)
        {
            pr={-cnt,penalty};
        }
    }
    sort(vals.begin(),vals.end());
    cout<<lower_bound(vals.begin(),vals.end(),pr)-vals.begin()+1<<"\n";
}
int main()
{
	long long t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}