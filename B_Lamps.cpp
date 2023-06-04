#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    cin>>n;
    map<long long int,priority_queue<long long int>>pq;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        pq[x].push(y);
    }
    long long int ans=0;
    for(auto &it:pq)
    {
        long long int f=it.first;
        priority_queue<long long int>s=it.second;
        while (f>0 and not s.empty())
        {
            ans+=s.top();
            s.pop();
            f--;
            // s--;
        }
    }
    cout<<ans<<"\n";
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