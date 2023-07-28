#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first<b.first)
    {
        return true;
    }
    else if(a.first==b.first)
    {
        if(a.second<b.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    queue<int>q;
    q.push(1);
    vector<pair<int,int>>vp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        int m=a[i]%k;
        if(q.size() && !m)
        {
            // vp.push_back({q.front(),i+1});
            // q.pop();
            a[i]=k;
        }
        else
        {
            // q.push(i+1);
            a[i]=m;
        }
        if(q.size())
        {
            vp.emplace_back(a[i],-i);
        }
    }
    sort(vp.rbegin(),vp.rend(),cmp);
    for(auto& it:vp)
    {
        int p=it.first;
        int k=it.second;
        k=-k;
        ++k;

        if(q.size())
        {
            cout<<k<<" ";
        }
    }
    cout<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		sol();
    }
}