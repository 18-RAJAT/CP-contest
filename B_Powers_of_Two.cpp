#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    unordered_map<long long int,long long int>pairOfIndexes;
    long long int exist=0;
    for(long long int i=0;i<n;++i)
    {
        long long int powers;
        cin>>powers;

        long long int numbers=1;
        long long int maximumLimit=INT_MAX;
        while(numbers<=maximumLimit)
        {
            exist+=pairOfIndexes[numbers-powers];
            numbers*=2;
        }
        pairOfIndexes[powers]++;
    }
    cout<<exist<<"\n";
}