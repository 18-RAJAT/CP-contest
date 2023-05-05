#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,m;
    cin>>n>>m;
    function<void(int,int)>primeFactors=[&](int n,int m)->void
    {
        if(n%2==0)
        {
            if(m>=2)
            {
                cout<<"NO"<<"\n";
            }
            else
            {
                cout<<"YES"<<"\n";
            }
            return;
        }
        for(int i=3;i<=sqrt(n);i+=2)
        {
            if(n%i==0)
            {
                if(i<=m)
                {
                    cout<<"NO"<<"\n";
                }
                else
                {
                    cout<<"YES"<<"\n";
                }
                return;
            }
        }
        cout<<"YES"<<"\n";
        return;
    };

    if(n<=m and n!=1 and m!=1)
    {
        cout<<"NO"<<"\n";
        return;
    }
    primeFactors(n,m);
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