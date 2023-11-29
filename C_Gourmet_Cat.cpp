#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    int mn1=min(a[0]/3,a[1]/2);
    int mn2=min(mn1,a[2]/2);
    int weeks=min(mn1,mn2);
    int possible[14]={0,1,2,0,2,1,0,0,1,2,0,2,1,0};
    int maximum=0;
    a[0]-=weeks*3,a[1]-=weeks*2,a[2]-=weeks*2;
    for(int i=0;i<7;++i)
    {
        int cnt=0;
        int tmp=i;
        int pairs[3]={a[0],a[1],a[2]};
        while(pairs[possible[tmp]]>0)
        {
            cnt++;
            pairs[possible[tmp]]--;
            tmp=(tmp+1)%7;
        }
        maximum=max(maximum,cnt);
    }
    cout<<weeks*7+maximum<<endl;
}
signed main()
{
    sol();
    return 0;
}