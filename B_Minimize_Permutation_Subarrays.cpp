#include<bits/stdc++.h>
using namespace std;

void sol()
{
	long long int n;
	cin>>n;
	vector<long long int>arr(n);
	for(long long int i=0;i<n;++i)
	{
		cin>>arr[i];
	}
	long long int count1=0,count2=0,count3=0;

	while(arr[count1]!=n)
	{
		count1++;
	}
	while(arr[count2]!=1)
	{
		count2++;
	}
	while(arr[count3]!=2)
	{
		count3++;
	}
	count1++,count2++,count3++;

	if((count1<count2 and count2<count3) or (count2>count3 and count1>count2))
	{
		cout<<count2<<" "<<count1<<"\n";
	}
	else if((count2<count1 and count1<count3) or (count1>count3 and count1<count2))
	{
		cout<<count3<<" "<<count3<<"\n";
	}
	else
	{
		cout<<count3<<" "<<count1<<"\n";
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