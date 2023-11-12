#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    char ch='a',ch1='z';
    for(int i=0;i<n;++i)
    {
        if(s[i]<=ch && ch<=ch1)
        {
            s[i]=ch;
            ch++;
        }
    }
    cout<<((ch>ch1)?s:"-1")<<endl;
}
signed main()
{
    sol();
    return 0;
}