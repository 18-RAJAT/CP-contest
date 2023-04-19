#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int array[n];
    memset(array,0,sizeof(array));

    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    for(int i=1;i<n;++i)
    {
        long long int last=array[i-1];
        long long int current=array[i];

        array[i-1]=current&last;
        array[i]=current|last;
    }
    long long int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=array[i]*array[i];
    }
    printf("%lld\n",sum);
    return 0;
}



string removeKDigits(string num, int k) 
{
    // Write your code here.
    using lambda function
}
