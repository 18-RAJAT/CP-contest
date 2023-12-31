#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    int cnt=(n-3)/2;
    int c=cnt;
    while(c-->=0)
    {
        cout<<1;
        c++;
        int make_cpy=c;
        while(make_cpy--)
        cout<<0;
        cout<<6;
        make_cpy=c;
        while(make_cpy--)
        cout<<0;
        cout<<9;
        make_cpy=n-3-c*2;
        while(make_cpy--)
        cout<<0;
        c--;
        // cout<<endl;
        cout<<" ";
    }
    cout<<196;
    // cout<<" ";
    // cout<<endl;
    int again_cnt=n-3;//to make 196=1+9+6=3 digits
    while(again_cnt--)
    cout<<0;
    // cout<<endl;
    cout<<" ";
    c=cnt;
    while(c-->=0)
    {
        cout<<9;
        c++;
        int make_cpy=c;
        while(make_cpy--)
        cout<<0;
        cout<<6;
        make_cpy=c;
        while(make_cpy--)
        cout<<0;
        cout<<1;
        make_cpy=n-3-cnt*2;
        while(make_cpy--)
        cout<<0;
        c--;
        // cout<<endl;
        cout<<" ";
        // cout<<endl;
    }
    // cout<<691;
    cout<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}