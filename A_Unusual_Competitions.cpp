#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int balanceBracket=0;
    int count=0;
    int ans=0;

    for(auto it:s)
    {
        if(it=='(')
        {
            balanceBracket++;
        }
        else
        {
            balanceBracket--;
        }
        if(balanceBracket<0)
        {
            if(count==0)
            {
                count=2;
            }
            else
            {
                count++;
            }
        }
        else
        {
            ans+=count;
            count=0;
        }
    }
    ans+=count;
    if(balanceBracket!=0)
    {
        cout<<-1<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
}