#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    int n;
        cin>>n;
        vector<ll>arr(n);
        for(int i=0;i<n;i+=1)
        {
            cin>>arr[i];
        }
        ll mn=INT_MAX;
        for(int i=0;i<n-1;++i)
        {
            if(arr[i+1]-arr[i]<0)
            {
                cout<<"0\n";
                return;
            }
            if(arr[i+1]-arr[i]<mn)
            {
                mn=arr[i+1]-arr[i];
            }
        }
        cout<<mn/2+1<<"\n";
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