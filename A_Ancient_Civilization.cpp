#include<bits/stdc++.h>
#define Rajat_Joshi            main;
#define  CSE             ios_base::sync_with_stdio(false);
#define Joshi           cin.tie(NULL);
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define read(type) readInt<type>()
#define ll long long
#define nL


#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
int n, k;
int a[100000], b[100000];
int main()
{
	int t;
	cin>> t;
	while(t--)
	{
		memset(b,0,sizeof(b));
		cin>>n>>k;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			int x=0;
			while(a[i])
			{
				if(a[i]%2==1)
					b[x]++;
				a[i]/=2;
				x++;
			}
		}
		for(int i=0;i<k;i++)
		{
			if(b[i]>n/2)ans+=(1<<i);
			
		}
		cout<<ans<<endl;
	}
    return 0;
}