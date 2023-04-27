#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n,k;
    cin>>n>>k;
    if(k>100000001)
    {
        cout<<-1<<"\n";
        return;
    }
    long long int ans=-1;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i!=0)
        {
            continue;
        }
        long long int div=n/i;
        long long int take=k+k*k;
        if(n<(take)*i/2)
        {
            continue;
        }
        
        ans=max<long long>(ans,i);

        if(n<(take)*div/2)
        {
            continue;
        }
        // ans=i;
        ans=max<long long>(ans,div);
    }
    if(ans==-1)
    {
        cout<<-1<<"\n";
    }
    else
    {
        long long int temp=ans;
        long long int count=0;
        for(int i=0;i<k-1;++i)
        {
            cout<<temp<<" ";
            // temp+=ans;
            // count++;
            count+=temp;
            temp+=ans;
        }
        long long int left=n-count;
        cout<<left<<"\n";
    }
}

int main()
{
    sol();
    return 0;
}