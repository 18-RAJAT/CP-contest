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
int n;
        cin >> n;
        vector<int>a(n);
        vector<int>b(n);
        for (auto &x : a)
            cin >> x;

        for (auto &x : b)
            cin >> x;

        bool flag = true;
        for (int i = 0; i < n; i++)
            if (b[i] > a[i])
                flag = false;

        if (!flag)
        {
            cout << "NO\n";
            continue;
        }

        int mn = 0;
        for (int i = 0; i < n; i++)
        {
            mn = max(mn, a[i] - b[i]);
        }

        for (int i = 0; i < n; i++)
            a[i] = max(0, a[i] - mn);

        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                flag = false;

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
}
return 0;
}