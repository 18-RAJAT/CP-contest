#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n,0);
    for(int i=0;i<m;++i)
    {
        a[*(istream_iterator<int>(cin))-1]++;
    }
    cout<<*min_element(a.begin(),a.end());
}
signed main()
{
    sol();
    return 0;
}