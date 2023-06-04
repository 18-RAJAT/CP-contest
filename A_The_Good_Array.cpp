#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<"\n";
    }
    else if(n<k)
    {
        cout<<0<<"\n";
    }
    else
    {
        int res=n;
        for(int i=1;i<=n;++i)
        {
            int vals1=(i-2+k)/k;
            int vals2=(n-i-1+k)/k;
            int val=vals1+vals2;
            res=min<int>(res,val);
        }
        res++;
        cout<<res<<"\n";
    }
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