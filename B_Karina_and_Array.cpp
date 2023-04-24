#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    cin>>n;
    vector<long long int>array(n);

    for(auto& it:array)
    {
        cin>>it;
    }
    sort(array.begin(),array.end());
    long long int first=array[0];
    long long int second=array[1];

    long long int last=array[n-1];
    long long int secondLast=array[n-2];
    cout<<max(first*second,last*secondLast)<<"\n";
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
