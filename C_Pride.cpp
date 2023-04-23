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
	int n;
	cin>>n;
	int array[2005];
	memset(array,0,sizeof(array));
	
	int GCD=0;
	int operations=0;
	
	for(int i=0;i<n;++i)
	{
		cin>>array[i];
		GCD=__gcd(array[i],GCD);
		
		if(array[i]==1)
		{
			operations++;
		}
	}
	if(operations)
	{
		cout<<n-operations;
		return 0;
	}
	if(GCD>1)
	{
		cout<<"-1";
		return 0;
	}
	int minimumNumberOfOperations=1e9;
	for(int i=0;i<=n;++i)
	{
		int restore=array[i];
		for(int j=i+1;j<n;++j)
		{
			restore=__gcd(restore,array[j]);
			
			if(restore==1)
			{
				minimumNumberOfOperations=min(minimumNumberOfOperations,j-i);
			}
		}
	}
	cout<<abs(n+minimumNumberOfOperations-1);
	return 0;
}