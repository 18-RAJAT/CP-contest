#include<bits/stdc++.h>
using namespace std;



void sol()
{
    string s;
    cin>>s;
    long long int digit=1;
    if(s[0]=='0')
    {
        digit=0;
    }
    for(long long int i=0;i<s.size();++i)
    {
        if(s[i]=='?')
        {
            if(not i)
            {
                digit*=9;
            }
            else
            {
                digit*=10;
            }
        }
    }
    cout<<digit<<"\n";
}
int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        sol();
    }
    return 0;
}