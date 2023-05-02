#include<bits/stdc++.h>
using namespace std;

void sol()
{
    auto odd=[&](long long int x)->long long int
    {
        if(x&1)
        {
            return x;
        }
        else
        {
            return x-1;
        }
    };
    
    auto query=[&](long long int x)->long long int
    {
        return x*(x+1)/2-(odd(x)+1)*(odd(x)+1)/2;
    };
    long long int l,r;
    cin>>l>>r;
    cout<<query(r)-query(l-1)<<"\n";
}

int main()
{
    long long int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
}