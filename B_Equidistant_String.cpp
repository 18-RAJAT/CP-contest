#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;cin>>a>>b;
    string ans="";
    int idx=0;
    for(int i=0;i<a.size();++i)
    {
        if(a[i]==b[i])
        {
            ans+=a[i];
        }
        else
        {
            if(idx%2)
            {
                ans+=a[i];
            }
            else
            {
                ans+=b[i];
            }
            idx++;
        }
    }
    cout<<((idx%2)?"impossible":ans)<<"\n";
}