#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    int flag=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;

        int S=sqrt(x);
        if((S*S)!=x)
        {
            flag=1;
        }
    }
    cout<<((flag)?"YES":"NO")<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        sol();
    }
    return 0;
}