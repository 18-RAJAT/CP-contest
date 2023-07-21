#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    double res=r/(1/sin(3.14159265358979323846/n)-1);
    cout<<fixed<<setprecision(10)<<res;
}