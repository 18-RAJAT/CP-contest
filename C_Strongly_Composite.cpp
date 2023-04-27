#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sol()
{
    ll n;
    cin>>n;
    vector<int>array(n);
    ll count=0;
    //sqrt
    auto isPrime=[&](int n)->bool
    {
        for(int i=2;i*i<=n;++i)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    };
    unordered_map<int,int>composite;
    for(auto& it:array)
    {
        cin>>it;
        int strongly=it;

        // if(isPrime(it))
        // {
        //     continue;
        // }
        // for(int i=2;i*i<=it;++i)
        // for(int i=2;i*i<=strongly;++i)
        for(int i=2;i<=sqrt(strongly);++i)
        {
            while(strongly%i==0)
            {
                strongly/=i;
                // strongly=i;
                // break;
                composite[i]++;
            }
        }
        if(strongly>1)
        {
            composite[strongly]++;
        }
    }
    int maxCount=0;
    int sum=0;
    for(auto&[it,itr]:composite)
    {
        maxCount+=itr/2;
        // if(itr>maxCount)
        // {
        //     maxCount=itr;
        //     sum=it;
        // }
        sum+=itr-itr/2*2;//by this we can get the number of odd numbers
    }
    ll satisfy=maxCount+sum/3;//by this we can get the number of even numbers
    cout<<satisfy<<"\n";
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