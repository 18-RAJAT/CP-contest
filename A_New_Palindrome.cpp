#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;
        bool flag=false;

        for(int i=1;i<s.size()/2;++i)
        {
            if(s[i]!=s[i-1])
            {
                flag=true;
            }
        }
        cout<<((flag)?"YES":"NO")<<"\n";
    }
    return 0;
}