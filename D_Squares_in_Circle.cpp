#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int r;
    cin>>r;
    int chk=4*r*r,sq=r-1,ans=0,j=sq;
    for(int i=0;i<=sq;++i)
    {
        int a=2*i+1,a2=a*a;
        while(j>=0)
        {
            int b=2*j+1,b2=b*b;
            if(a2+b2<=chk)break;
            j--;
        }
        //2,2->>10 | 3->1->>6 ---- 37
        if(j<0)break;
        (i==0)?ans+=1+2*j:ans+=2+4*j;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}