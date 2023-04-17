#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    n++;

    cout<<3*n+1<<"\n";
    cout<<"0 0\n";

    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<i<<"\n";
        cout<<i<<" "<<i-1<<"\n";
        cout<<i-1<<" "<<i<<"\n";
    }
}