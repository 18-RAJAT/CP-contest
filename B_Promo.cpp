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
const int N = 2e5+10;

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
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// int ttt; cin >> ttt;
// while(ttt--) {
//_______________________________________________________//
Rajat_Joshi CSE;
   int n,q;
	cin >> n >> q;
	long long a[n+1],b[n+1];
	b[0]=0;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (int i=1; i<=n; i++){
		b[i]=b[i-1]+a[i];
	}
	long long x,y;
	for (int i=0; i<q; i++){
		cin >> x >> y;
		cout << b[x]-b[x-y] <<"\n"; 
	}
return 0;
}



