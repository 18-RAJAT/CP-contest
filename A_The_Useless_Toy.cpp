#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    char s,e;
    int n;
    cin>>s>>e>>n;
    if(n%4==0||n%4==2)
    {
        cout<<"undefined"<<endl;
    }
    else
    {
        if(n%4==1)
        {
            if(s=='^')
            {
                (e=='>')?cout<<"cw"<<endl:cout<<"ccw"<<endl;
            }
            else if(s=='>')
            {
                (e=='v')?cout<<"cw"<<endl:cout<<"ccw"<<endl;
            }
            else if(s=='v')
            {
                (e=='<')?cout<<"cw"<<endl:cout<<"ccw"<<endl;
            }
            else
            {
                (e=='^')?cout<<"cw"<<endl:cout<<"ccw"<<endl;
            }
        }
        else
        {
            if(s=='^')
            {
                (e=='<')?cout<<"cw"<<endl:cout<<"ccw"<<endl;
            }
            else if(s=='>')
            {
                (e=='^')?cout<<"cw"<<endl:cout<<"ccw"<<endl;
            }
            else if(s=='v')
            {
                (e=='>')?cout<<"cw"<<endl:cout<<"ccw"<<endl;
            }
            else
            {
                (e=='v')?cout<<"cw"<<endl:cout<<"ccw"<<endl;
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}