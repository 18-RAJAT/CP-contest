#include<bits/stdc++.h>
using namespace std;

void sol()
{
    string s;
    cin>>s;
    int x;
    cin>>x;
    int n=s.size();
    string str="";
    for(int i=0;i<n;++i)
    {
        str+='1';
    }
    bool flag=true;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            if(i-x>0)
            {
                str[i-x]='0';
            }
            if(i+x<n)
            {
                str[i+x]='0';
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')
        {
            if(str[i-x]!='1' and str[i+x]!='1' and str[i-x-1]!='1')
            {
                flag=false;
            }
        }
    }
    if(flag==0)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<str<<"\n";
    }
}
// 1111100000001100110011000001010110000101111001100111100111011111001

int main()
{
    int testCase;
    cin>>testCase;
    while(testCase-->0)
    {
        sol();
    }
    return 0;
}