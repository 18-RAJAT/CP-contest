#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if((x|a[i])<=x)
        {
            ans|=a[i];
        }
        else
        {
            break;
        }
    }
    for(int i=0;i<n;++i)
    {
        if((x|b[i])<=x)
        {
            ans|=b[i];
        }
        else
        {
            break;
        }
    }
    for(int i=0;i<n;++i)
    {
        if((x|c[i])<=x)
        {
            ans|=c[i];
        }
        else
        {
            break;
        }
    }
    cout<<((ans==x)?"Yes\n":"No\n");
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