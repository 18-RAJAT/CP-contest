#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int ans=1;
        for(int i=1,mov=1;i<n;++i)
        {
            if(a[i]-a[i-1]>k)
            {
                mov=1;
            }
            else
            {
                mov++;
            }
            ans=max<int>(ans,mov);
        }
        cout<<abs(n-ans)<<'\n';
	}
}