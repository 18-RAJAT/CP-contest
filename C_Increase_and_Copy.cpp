#include<bits/stdc++.h>
using namespace std;


void sol()
{

    auto moves=[&](long long int x,long long int n)->long long int
    {
        if(n<x)
        {
            return 1;
        }
        long long int con1=(x-1)/2;
        long long int con2=(x-1)/2+1;


        long long int obtain1=(x-con1)*(con1+1);
        long long int obtain2=(x-con2)*(con2+1);
        
        long long int maximum=max(obtain1,obtain2);
        if(n<=maximum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };

    long long int n;
    cin>>n;

    long long int start=1;
    long long int end=1e15;
    long long int minimumNumberOfMoves=1e18;

    while(start<=end)
    {
        long long int mid=start+(end-start)/2;
        if(moves(mid,n))
        {
            minimumNumberOfMoves=min(minimumNumberOfMoves,mid);
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    cout<<minimumNumberOfMoves-1<<"\n";
}

int main()
{
    int testCase;
    cin>>testCase;

    while(testCase--)
    {
        sol();
    }
}