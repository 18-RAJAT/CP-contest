#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),sets(n);
    for(auto& it:a)cin>>it;
    int sub=0,add=0;
    for(int i=n-1;~i;--i)
    {
        sets[i]=a[i]-(add-sub),add+=sets[i];
        swap(add,sub);
    }
    for(auto& it:sets)cout<<it<<" ";
}
signed main()
{
    sol();
    return 0;
}