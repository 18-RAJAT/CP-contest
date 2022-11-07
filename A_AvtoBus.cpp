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
#define iminimum INT_minimum
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
 long long n; 
        cin>>n; 
        if(n%4!=0  and  n%4!=2 ) 
        { 
            cout<<"-1"<<endl; 
        } 
        else if (n<4) 
        cout<<"-1"<<endl; 
        else 
        { 
            ll minimum=n/6; 
            ll max=n/4; 
  
            if(n%6!=0) 
            { 
                cout<<(minimum+1)<<" "<<max<<endl; 
            } 
            else 
            { 
                cout<<minimum<<" "<<max<<endl; 
            } 
        } 
}
return 0;
}