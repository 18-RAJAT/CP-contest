#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>pref;
    for(int i=0;i<n-2;++i)
    {
        if(a[i+1]<=a[i] && a[i+2]<=a[i+1])
        {
            pref.push_back(i);
        }
    }
    for(int j=0;j<q;++j)
    {
        int l,r;
        cin>>l>>r;
        l--;
        int lb=lower_bound(pref.begin(),pref.end(),l)-pref.begin();
		int ub=lower_bound(pref.begin(),pref.end(),r-2)-pref.begin();
		int answer=r-l-(ub-lb);
		if(r-l<=2) 
        {
			answer=r-l;
		}
		printf("%d\n",answer);
    }
}