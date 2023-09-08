#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    string s;
    cin>>s;
    int arr[n+1];
    memset(arr,0,sizeof(arr));
    int x=0,y=0;
    if(s[0]=='1')
    {
        x=a[0];
    }
    else
    {
        y=a[0];
    }
    for(int i=1;i<s.size();++i)
    {
        //changing the array to prefix xor array of a array and then finding xor of all elements from i-1 to 0
        arr[i]=arr[i-1]^a[i-1];//1 2 3 4 5 6 7 8 9 10 finds xor of all elements from i-1 to 0.....
        if(s[i]=='1')
        {
            // x=max<int>(x,arr[i]);
            x^=a[i];
        }
        else
        {
            // y=max<int>(y,arr[i]);
            y^=a[i];
        }
        // cout<<x<<" "<<y<<endl;
    }
    arr[n]=arr[n-1]^a[n-1];//chk with n pos
    int query;
    cin>>query;
    while(query--)
    {
        int p;
        cin>>p;
        if(p==1)
        {
            int l,r;
            cin>>l>>r;
            x^=(arr[r]^arr[l-1]);//xor of all elements from l-1 to r
            y^=(arr[r]^arr[l-1]);
        }
        else
        {
            int l;
            cin>>l;
            cout<<((l==1)?x:y)<<endl;
        }
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	sol();
        assert((sizeof(int)*8)>=64);
    }
    return 0;
}