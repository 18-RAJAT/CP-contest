#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    int d=0,l=0,c=0,ans=0;
    int maxi=1e18;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(d==0)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
            else if(d==1 and l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(d==1 and l==1)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(d==0)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
            else if(d==1 and l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(d==1 and l==1)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(c==1 and l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(c==1 and l==1)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(c==1 and d==0)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
            else if(c==1 and d==1)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(l==1 and c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(l==1 and c==1)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(l==1 and d==0)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
            else if(l==1 and d==1)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(c==1 and d==0)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
            else if(c==1 and d==1)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(c==1 and l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(c==1 and l==1)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(l==1 and c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(l==1 and c==1)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(l==1 and c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(l==1 and c==1)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(c==1 and l==0)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
            else if(c==1 and l==1)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
        }
    }
    if(d==1 and l==1 and c==1)maxi=min(maxi,ans);
    d=0,l=0,c=0,ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(c==0)
            {
                if(s[i][j]=='*'||s[i][j]=='&'||s[i][j]=='#')
                {
                    ans+=j;
                    c=1;
                }
                else if(s[i][m-j-1]=='*'||s[i][m-j-1]=='&'||s[i][m-j-1]=='#')
                {
                    ans+=j+1;
                    c=1;
                }
                if(c)break;
            }
            else if(c==1 and d==0)
            {
                if(isdigit(s[i][j]))
                {
                    ans+=j;
                    d=1;
                }
                else if(isdigit(s[i][m-j-1]))
                {
                    ans+=j+1;
                    d=1;
                }
                if(d)break;
            }
            else if(c==1 and d==1)
            {
                if(isalpha(s[i][j]))
                {
                    ans+=j;
                    l=1;
                }
                else if(isalpha(s[i][m-j-1]))
                {
                    ans+=j+1;
                    l=1;
                }
                if(l)break;
            }
        }
    }
    cout<<maxi;
}
signed main()
{
    sol();
    return 0;
}