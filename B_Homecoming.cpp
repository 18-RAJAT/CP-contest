#include<bits/stdc++.h>
using namespace std;

char ch[100001];
void sol()
{
    int a,b,p;
    bool ok=false;
    cin>>a>>b>>p>>ch+1;
    int length=strlen(ch+1);
    for(int i=length-1;i>=1;--i)
    {
        int j=i;
        while(ch[i]==ch[j])--j;
        if(ch[i]=='A')
        {
            p-=a;
        }
        else
        {
            p-=b;
        }
        if(p<0)
        {
            ok=true;
            cout<<i+1<<"\n";
            return;
        }
        //move to next
        i=j;++i;
    }
    if(not ok)
    {
        cout<<1<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        sol();
    }
    return 0;
}