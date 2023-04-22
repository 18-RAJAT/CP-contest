#include<bits/stdc++.h>
using namespace std;

int main()
{
    int garland;
    cin>>garland;

    string diverse;
    cin>>diverse;

    int count=0;
    for(int i=1;i<garland;++i)
    {
        if(diverse[i]==diverse[i-1])
        {
            if(diverse[i]=='R')
            {
                if(diverse[i+1]=='G')
                {
                    diverse[i]='B';
                    count++;
                }
                else
                {
                    diverse[i]='G';
                    count++;
                }
            }
            else if(diverse[i]=='G')
            {
                if(diverse[i+1]=='R')
                {
                    diverse[i]='B';
                    count++;
                }
                else
                {
                    diverse[i]='R';
                    count++;
                }
            }
            else if(diverse[i]=='B')
            {
                if(diverse[i+1]=='R')
                {
                    diverse[i]='G';
                    count++;
                }
                else
                {
                    diverse[i]='R';
                    count++;
                }
            }
        }
    }
    cout<<count<<"\n";
    cout<<diverse<<"\n";
}