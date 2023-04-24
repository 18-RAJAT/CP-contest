#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    cin>>n;

    //n*n=n^2
    //or n+1*n+1+1;//get
    long long int cinnabon=n*n;
    long long int layers=2*n;
    long long int rolls=2;

    cout<<layers+rolls+cinnabon<<"\n";
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}
