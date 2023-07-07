#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long n,b,h;
    cin>>n>>b>>h;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long count=0;
    vector<int>tmp;
    for(int i=0;i<n;++i)
    {
        if(a[i]<count)
        {
            tmp.push_back(count-a[i]);
        }
        count=h+a[i];
    }
    double res=n*b*h*1.0;res/=2;
    double cnt=0;
    for(auto& it:tmp)
    {
        // cnt++;
        cnt+=it*it;
    }
    cnt=(cnt*1.0*b)/(2.0*h);
    res-=cnt;
    cout<<double(res)<<"\n";
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