#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    int vis=0;
    for(int i=2;i<=sqrt(n);++i)
    {
        int tot=i*i+i+1;
        while(tot<=n)
        {
            if(tot==n)
            {
                vis=1;
                break;
            }
            tot=tot*i+1;
        }
        if(vis<0)
        {
            break;
        }
    }
    cout<<(vis?"YES\n":"NO\n");
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