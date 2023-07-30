#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
	int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];

    }
    int count=0;
    for(int i=0;i<n;i++)
    { 
        if(i+1==a[i])
        {
            count++;
        }
    } 
    int ans=count+1;
    cout<<ans/2<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		sol();
    }
}