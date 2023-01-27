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
#define aaa first
#define bbb second
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
 int ttt; 
cin >> ttt;
while(ttt--) {
//_______________________________________________________//
Rajat_Joshi CSE;
{
{ 
 int n; 
 cin >> n; 
 int arr[n][n-1]; 
 for(int i=0;i<n;i++) 
 { 
  for(int j=0;j<n-1;j++) 
  { 
   cin >> arr[i][j]; 
  } 
 } 
 vector<int>ans; 
 vector<pair<int,int>>vp; 

    for(int i=0;i<n-1;++i)
    {
        set<int>st;
        vector<int>vv;
        for(int j=0;j<n;++j)
        {
            int k=st.size();
            st.insert(arr[j][i]);
            if(k!=st.size()) vv.pb(arr[j][i]);
        }
        vp.pb(make_pair(vv[0],vv[1]));
    }
    int x=vp[0].aaa;
    int y=vp[0].bbb;
    int x1=vp[1].aaa;
    int y1=vp[1].bbb;

    int r; 
    if(x==x1 or x==y1) r=y; 
    else r=x; 
    cout<<r<<' '; 
    for(int i=0;i<vp.size();++i)
    { 
        x=vp[i].aaa; 
        y=vp[i].bbb; 
    if(x!=r)
    { 
        cout << x; 
        r=x; 
    } 
    else 
    { 
        cout << y; 
        r=y; 
    } 
        cout << ' '; 
    }
    cout<<endl;
}  
}
}
return 0;
}