#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,k;
    cin>>n>>k;
    function<int(vector<int>&,int,int)>chkMinPow=[&](vector<int>&sus,int n,int k)->int
    {
        vector<int>diff;
        int sum=0;
        for(int i=1;i<n;i++)
        {
            diff.push_back(abs<int>(sus[i]-sus[i-1]));
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<n-k;i++)
        {
            sum+=diff[i];
        }
        return sum;
    };
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int minPow=chkMinPow(arr,n,k);
    cout<<minPow<<"\n";

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