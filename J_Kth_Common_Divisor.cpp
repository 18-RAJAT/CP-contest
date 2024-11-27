#include<bits/stdc++.h>
using namespace std;
#define int long long 

int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
// void divs(int n,vector<int>& Div)
// {
//     for(int i=1;i*i<=n;++i)
//     {
//         if(n%i==0)
//         {
//             Div.push_back(i);
//             if(i!=n/i)
//             {
//                 Div.push_back(n/i);
//             }
//         }
//     }
//     sort(Div.begin(),Div.end());
// }
void sol()
{
    int a,b,k;
    cin>>a>>b>>k;
    int G=gcd(a,b);
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i*i<=G;++i)
    {
        if(G%i==0)
        {
            pq.push(i);
            if(i!=G/i)
            {
                pq.push(G/i);
            }
        }
    }
    for(int i=0;i<k-1;++i)pq.pop();
    cout<<pq.top()<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}