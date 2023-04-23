// Problem: C. Pride
// Contest: Codeforces - Codeforces Round 446 (Div. 2)
// URL: https://codeforces.com/contest/892/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Auther: Rajat.18
// Created: Sun 23/4/2023 16:32:33 GMT+5:30,India
//
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	long long int array[n];
	memset(array,0,sizeof(array));
	
	map<long long int,long long int>mp;
	int pos=0;
	for(int i=0;i<n;++i)
	{
		cin>>array[i];
		if(array[i]==1)
		{
			pos++;
		}
	}
	long long int G=array[0];
	for(int i=1;i<n;++i)
	{
		G=__gcd(G,array[i]);
	}
	if(G!=1)
	{
		cout<<-1<<"\n";
	}
	else if(pos>0)
	{
		cout<<n-pos<<"\n";
	}
	else
	{
		long long int minimumOperations=1e18;
		for(int i=0;i<n-1;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				long long int greatest=__gcd(array[i],array[j]);
				if(greatest==1)
				{
					minimumOperations=min<long long int>(mimimumOperations,j-i);
					break;
				}
			}
		}
		cout<<minimumOperations+n-1-pos<<"\n";
	}
}