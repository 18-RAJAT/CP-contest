#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int n)
{
    if(n==0){return 1;}
    else if(n<=9){return n;}
    else{return max(recur(n%10)*recur(n/10),recur(n/10-1)*9);}
}
void sol()
{
    int n;
    cin>>n;
    cout<<recur(n)<<endl;
}
signed main()
{
    sol();
    return 0;
}