#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        a.resize(n+1);
        for(ll i=1;i<=n;i++)
        {
        	cin>>a[i];
        }
        vector<ll>b(51),c(51);
        ll k=0;
        ll pos1=max_element(a.begin()+1,a.end())-a.begin();
        ll pos2=min_element(a.begin()+1,a.end())-a.begin();
        if(abs(a[pos1])>=abs(a[pos2]))
        {
        	for(ll i=2;i<=n;i++)
        	{
        		while(a[i-1]>a[i])
        		{
        			b[k]=i,c[k]=pos1;
        			k++;
        			a[i]+=a[pos1];
                    pos1=max_element(a.begin()+1,a.end())-a.begin();
        		}
        	}
        }
        else if(abs(a[pos1])<=abs(a[pos2]))
        {
        	for(ll i=n-1;i>=1;i--)
        	{
        		while(a[i]>a[i+1])
        		{
        			b[k]=i,c[k]=pos2;
        			k++;
        			a[i]+=a[pos2];
                    pos2=min_element(a.begin()+1,a.end())-a.begin();
        		}
        	}
        }
        cout<<k<<"\n";
        for(ll i=0;i<k;i++)
        {
        	cout<<b[i]<<" "<<c[i]<<"\n";
        }
    }
}