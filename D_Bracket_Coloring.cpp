#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int colors[n];
        memset(colors,0,sizeof(colors));

        int count=0;
        int ok=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
            {
                ok++;
            }
            else
            {
                ok--;
            }
            if(ok<0)
            {
                // ok=0;
                count++;
                break;
            }
        }
        if(count!=0)
        {
            cout<<-1<<"\n";
            continue;
        }

        int count1=0;
        ok=0;

        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
            {
                ok++;
            }
            else
            {
                ok--;
            }
            if(ok<0)
            {
                count1++;
                break;
            }
        }
        ok=0;

        // for(int i=n-1;i>=0;--i)
        for(int i=0;i<n;++i)
        {
            if(s[i]==')')
            {
                ok++;
            }
            else
            {
                ok--;
            }
            if(ok<0)
            {
                count1++;
                break;
            }
        }
        //check less than 2 
        if(count1<2)
        {
            cout<<1<<"\n";
            for(int i=0;i<n;++i)
            {
                // cout<<s[i];
                cout<<1<<" ";
            }
            cout<<"\n";
            // continue;
        }
        else
        {
            int first=0,last=n-1;

            while(first<last)
            {
                if(s[first]==')' and s[last]==')')
                {
                    colors[first++]=2;
                    colors[last--]=1;
                }
                else if(s[first]=='(' and s[last]==')')
                {
                    colors[first++]=1;
                    colors[last--]=2;
                }
                else
                {
                    first++;
                    last--;
                }
            }
            cout<<2<<"\n";
            for(int i=0;i<n;++i)
            {
                cout<<colors[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}