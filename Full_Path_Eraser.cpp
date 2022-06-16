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

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int ttt; cin >> ttt;
while(ttt--) {
//_______________________________________________________//
Rajat_Joshi CSE;

void dfs(int s,vector<int>adj[],bool visited[])
{
    stack<int>stk;
    stk.push(s);
    visited[s]=true;

    while(!stk.empty())
    {
        int u=stk.top();
        cout<<u;
        stk.pop();

        for(int i=0;i<adj[u].size();++i)
        {
            if(!visited[adj[u][i]])
            {
                stk.push(adj[u][i]);
                visited[adj[u][i]]=true;
            }
        }
    }
int n;cin>>n;
vector<int>a(n);
vector<int>b(n);
vector<int>c(n);

int count=0;
unordered_map<int,vector<int>>ump;
for(int i=0;i<n;++i){cin>>a[i];}

for(int i=0;i<n-1;++i)
{
int x,y;cin>>x>>y;
ump[x].pb(y);
ump[y].pb(x);
}
dfs(a[0],ump,visited);
}
cout<<count<<"\n";
}
return 0;
}
