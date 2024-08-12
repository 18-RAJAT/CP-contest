#include<bits/stdc++.h>
using namespace std;
#define int long long
int distance(array<int,2>a,array<int,2>b)
{
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
    }
    array<int,2>pointX,pointY;
    cin>>pointX[0]>>pointX[1]>>pointY[0]>>pointY[1];
    for(int i=0;i<n;++i)
    {
        if(distance(a[i],pointY)<=distance(pointX,pointY))
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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