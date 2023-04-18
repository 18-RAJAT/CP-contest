#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int a,b,n;
    cin>>a>>b>>n;

    long long int movement=0;

    while(true)
    {
        long long int maximumA_B=max(a,b);
        if(n<maximumA_B)
        {
            break;
        }
        if(a<b)
        {
            a+=b;
        }
        else
        {
            b+=a;
        }
        movement++;
    }
    printf("%d\n",movement);
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