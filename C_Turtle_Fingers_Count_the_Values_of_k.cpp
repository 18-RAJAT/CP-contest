#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,l;
    cin>>a>>b>>l;
    set<int>s;
    int ans=1;
    while(l%ans==0)
    {
        int y=1;
        while((l/ans)%y==0)
        {
            s.insert((l/ans)/y);
            y*=b;
        }
        ans*=a;
    }
    cout<<s.size()<<endl;
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

















