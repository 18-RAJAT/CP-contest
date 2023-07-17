#include<bits/stdc++.h>
using namespace std;

void sol()
{
	int n,m,k;
    int a,b;
    cin>>n>>m>>k;
    cin>>a>>b;
    int c=a+b;
    c%=2;
    int ok=1;
    for(int i=0;i<k;++i)
    {
        cin>>a>>b;
        if((a+b)%2==c)
        {
            ok=0;
        }
    }
    cout<<(!ok?"NO":"YES")<<"\n";
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