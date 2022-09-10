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
// int ttt; cin >> ttt;
// while(ttt--) {
//_______________________________________________________//
Rajat_Joshi CSE;
int n;cin>>n;int a[n];
for(int i=0;i<n;i++) cin>>a[i];
int ans=0;
// just calculate ans and with binary search assign two pointers
// and then calculate the ans
// and then check if the ans is greater than the current ans
// if yes then update the ans
// and then print the ans
//_______________________________________________________// 
    int i=0,j=0;
    ll counter=0;
    while(j<n){
        if(a[j]==0) counter++;
        while(counter>1){
            if(a[i]==0) counter--;
            i++;
        }
        ans=max(ans,j-i+1);
        j++;
    }
    cout<<ans;
return 0;
}