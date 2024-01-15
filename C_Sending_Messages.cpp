#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,f,a,b;
    cin>>n>>f>>a>>b;
    vector<int>ar;
    ar.assign(n,0);
    for(int i=0;i<n;++i)
    {
        cin>>ar[i];
    }
    int previous=0,ok=true;
    for(int i=0;i<n;++i)
    {
        int msg=ar[i]-previous;
        msg*=a;
        //can't send
        msg=min<int>(msg,b);
        if(f<=msg)
        {
            ok=false;
            break;
        }
        else
        {
            f-=msg;
            previous=ar[i];
        }
    }
    cout<<(ok?"YES":"NO")<<endl;
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