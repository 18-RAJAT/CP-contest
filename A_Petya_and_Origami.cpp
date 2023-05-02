#include<bits/stdc++.h>
using namespace std;

int main()
{
    auto compute=[&](int n,int k)->int
    {
        return (2*n+k-1)/k+(5*n+k-1)/k+(8*n+k-1)/k;
    };
    int n,k;
    cin>>n>>k;
    cout<<compute(n,k);
}