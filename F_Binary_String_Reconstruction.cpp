#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        string s="";
        if(b)
        {
            for(int i=0;i<=c;++i)
            {
                s+="1";
            }
            b--;
            for(    int i=0;i<=a;++i)
            {
                s+="0";
            }
            for(int i=0;i<b;++i)
            {
                s+=(s.back()=='0'?'1':'0');
            }
        }
        else if(c)
        {
            for(int i=0;i<=c;++i)
            {
                s+="1";
            }
        }
        else
        {
            for(int i=0;i<=a;++i)
            {
                s+="0";
            }
        }
        cout<<s<<"\n";
    }
}