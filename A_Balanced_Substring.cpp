#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;cin>>n;
        string s;cin>>s;
        bool found=false;
        for(int i=1;i<n;++i)
        {
            if(s[i]!=s[i-1])
            {
                found=true;
                cout<<i<<" "<<i+1<<"\n";
                break;
            }
        }
        if(not found)
        {
            cout<<"-1 -1\n";
        }
    }
    return 0;
}