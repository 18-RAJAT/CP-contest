#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    //1st way
    
    // int n,k;
	// cin>>n>>k;
	// int ans=0;
	// if((k-1)<=n)
	// {
	// 	ans=(k-1)/2;
	// }
	// else
	// {
	// 	ans=max<int>(n-(k)/2,ans);
	// }
	// cout<<ans<<endl;


    //2nd way
    int n,k;
    cin>>n>>k;
    int ans=min<int>(k-1,n)-(k/2+1)+1;
    cout<<max<int>(ans,0)<<endl;
}