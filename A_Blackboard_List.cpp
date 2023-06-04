#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    cin>>n;
    int count=0;
    vector<long long int>arr(n);
    for(auto&it:arr)
    {
        cin>>it;
        if(it<0)
        {
            count++;
        }
    }
    sort(arr.begin(),arr.end());
    if(count==0)
    {
        cout<<arr[n-1]-arr[0]<<"\n";
    }
    else
    {

        cout<<arr[0]<<"\n";
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