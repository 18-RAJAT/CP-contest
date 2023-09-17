#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
	    cin>>a>>b>>k;
	    cout<<((k&1)?(a-b)*(k/2)+a:((a-b)*(k/2)))<<endl;
    }
    return 0;
}