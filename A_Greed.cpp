#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;

    long long int aArray[1000000];memset(aArray,0,sizeof(aArray));
    long long int bArray[1000000];memset(bArray,0,sizeof(bArray));

    long long int sumOfAll=0;
    for(long long int i=0;i<n;++i)
    {
        cin>>aArray[i];
        sumOfAll+=aArray[i];
    }
    for(long long int i=0;i<n;++i)
    {
        cin>>bArray[i];
    }
    sort(bArray,bArray+n);
    if(bArray[n-1]+bArray[n-2]>=sumOfAll)
    {
        cout<<"YES"<<"\n";
    }
    else
    {
        cout<<"NO"<<"\n";
    }
}