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
 int n,ct=0; 
        cin>>n; 
        vector<int>v; 
  
        for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
} 
  
        for(int i=0;i<n;i++)
        { 
            if(v[i]%2==1)
            { 
                ct++; 
            } 
        } 
        if(ct>0)
        { 
            cout<<n-ct<<endl; 
        } 
        else{ 
            int ans=INT_MAX; 
            for(int i=0;i<n;i++)
            { 
                int ct1=0; 
                while(v[i]%2==0)
                { 
                    v[i]=v[i]/2; 
                    ct1++; 
                } 
                ans=min(ans,ct1); 
            } 
            cout<<(ans+n-1)<<endl; 
        } 
}
return 0;
}


