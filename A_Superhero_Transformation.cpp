#include<bits/stdc++.h>
using namespace std;
int main()
{
    auto func=[&](char c)->char
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            return 'v';
        }
        else
        {
            return 'c';
        }
    };
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length())
    {
        cout<<"No";
        return 0;
    }
    for(int i=0;i<s1.length();i++)
    {
        if(func(s1[i])!=func(s2[i]))
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}