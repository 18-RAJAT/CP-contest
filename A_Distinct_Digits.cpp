#include<bits/stdc++.h>
using namespace std;

int main()
{
    function<bool(int)>digitCheck=[&](int dig)->bool
    {
        vector<int>digit(10,0);
        while(dig)
        {
            if(digit[dig%10])
            {
                return false;
            }
            digit[dig%10]++;
            dig/=10;
        }
        return true;
    };
    long long int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;++i)
    {
        if(digitCheck(i))
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";
    return 0;
}