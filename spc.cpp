#include<bits/stdc++.h>
using namespace std;
#define int long long
int prime(int n)
{
    if(n<2)return false;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)return false;
    }
    return true;
}
bool spc(int n)
{
    if(n<=9)return prime(n);
    while(n>0)
    {
        if(!prime(n))return false;
        n/=10;
    }
    return true;
}
vector<int>print_spc(int n)
{
    vector<int>spc_num;
    for(int i=2;i<=n;++i)
    {
        if(spc(i))spc_num.emplace_back(i);
    }
    return spc_num;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>nums=print_spc(n);
    for(int i=0;i<nums.size();++i)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
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