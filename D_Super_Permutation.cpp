#include<bits/stdc++.h>
using namespace std;

void sol()
{

    long long int n;
    cin>>n;
    vector<long long int>super(n);
    long long int toCheckWithTimes=n/2;

    //base
    if(n==1)
    {
        cout<<1<<"\n";
        return;
    }
    //odd
    if(n%2!=0)
    {
        cout<<-1<<"\n";
        return;
    }
    vector<long long int>construct;

    auto print=[&](int n)->void
    {
        cout<<n<<" ";
    };
    long long int nonTrivial=0;
    for(long long int i=0;i<toCheckWithTimes;++i)
    {
        long long int superPermute=n-i-1;
        construct.push_back(i);
        // construct.push_back(2*i+2);
        // construct[i]=2*i+2;
        // construct[i+toCheckWithTimes]=2*i+1;
        construct.push_back(superPermute);
    }
    print(n);
    auto print1=[&]()->void
    {
        // for(int i=0;i<n;++i)
        // {
        //     cout<<construct[i]<<" ";
        // }
        // cout<<"\n";
        for(int i=0;i<n-1;++i)
        {
            // long long int sum=construct[i]+construct[(i+1)%n];
            // cout<<sum%n<<" ";
            long long int sum=construct[i+1]-construct[i]+n;
            cout<<sum%n<<" ";
        }
    };

    for(int i=0;i<n-1;++i)
    {
        // print(construct[i]);
        nonTrivial+=i;
        // nonTrivial+=abs(construct[i]-i);
        // print1();
        long long int sum=construct[i+1]-construct[i]+n;
        cout<<sum%n<<" ";
    }
    cout<<"\n";
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
