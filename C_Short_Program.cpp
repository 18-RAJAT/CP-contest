#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<char,int>>values;
    char ch;
    int val;
    for(int i=0;i<n;++i)
    {
        cin>>ch>>val;
        values.push_back(make_pair(ch,val));
    }
    auto check_and_or_xor=[&](int a,int b,char ch)->int
    {
        if(ch=='|')
        {
            return a|b;
        }
        else if(ch=='&')
        {
            return a&b;
        }
        else
        {
            return a^b;
        }
    };
    auto left_shift=[&](int a)->int
    {
        return (1<<a);
    };
    auto right_shift=[&](int a,int b)->int
    {
        return (a>>b);
    };
    int AndValue=0,OrValue=0;
    for(int bit=9;~bit;--bit)
    {
        int shift=left_shift(bit);
        int count=0;
        for(auto& val:values)
        {
            check_and_or_xor(shift,val.first,val.second);
            check_and_or_xor(count,val.first,val.second);
        }
        int shift1=right_shift(shift,bit);
        int shift2=right_shift(count,bit);

        if(shift1==shift2)
        {
            (shift1==1)?OrValue+=left_shift(bit):AndValue+=(bit);
        }
    }
    cout<<2<<endl;
    cout<<"&"<<" "<<AndValue<<endl;
    cout<<"|"<<" "<<OrValue<<endl;
    values.clear();
}
signed main()
{
    sol();
    return 0;
}