#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        cout<<max<int>({x*b,b*(a-x-1),y*a,a*(b-y-1)})<<"\n";
    }
}