#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        int previous=0,ok=0;
        int a,tmp;
        for(int i=1;i<=q;++i)
        {
            cin>>a;
            if(i==1)
            {
                tmp=a;
                cout<<"1";
                previous=tmp;
                continue;
            }
            if(a<previous)
            {
                if(ok==1)
                {
                    cout<<"0";
                }
                else
                {
                    if(tmp<a)
                    {
                        cout<<"0";
                    }
                    else
                    {
                        cout<<"1";
                        previous=a;
                        ok=1;
                    }
                }
            }
            else
            {
                if(ok==1)
                {
                    if(tmp<a)
                    {
                        cout<<"0";
                    }
                    else
                    {
                        cout<<"1";
                        previous=a;
                        ok=1;
                    }
                }
                else
                {
                    // cout<<"0";
                    previous=a;
                    // ok=0;
                    cout<<"1";
                }
            }
        }
        cout<<"\n";
    }
}