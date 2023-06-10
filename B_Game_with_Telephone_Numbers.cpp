#include<bits/stdc++.h>
using namespace std;
int n,a,b;
string s;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size()-10;++i)
    {
        if(s[i]=='8')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    cout<<((a>b)?"YES":"NO")<<"\n";
}