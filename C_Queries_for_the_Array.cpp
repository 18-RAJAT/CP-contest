#include<bits/stdc++.h>
using namespace std;
#define int long long
int sol(string s)
{
    int n=s.size();
    int charHash[n];
    memset(charHash,0,sizeof(charHash));
    int j=0;
    int consider=-1;
    int chk=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+')
        {
            charHash[j]=0;//0 for +
            j+=1;
        }
        // else if(s[i]=='-')
        // {
        //     charHash[j]=0;//0 for -
        //     j++;
        // }
        // else if(s[i]=='1')
        // {
        //     charHash[j]=1;//1 for 1
        //     j++;
        // }
        // else
        // {
        //     charHash[j]=2;//2 for 0
        //     j++;
        // }
        else if(s[i]=='-')
        {
            j-=1;
            // cout<<j<<" "<<consider<<endl;
            if(consider==j)//comp
            {
                consider--;
            }
            // else if(consider<j)
            // {
            //     chk=0;
            //     break;
            // }
        }

        /*
            ++0-+1-+0
            00000000
            00000001
            00000011
            00000111
            00001111
            00011111
            00111111
            01111111
            11111111
        */

        else if(s[i]=='1')
        {
            //chk here
            for(int i=consider;i<j;++i)
            {
                // cout<<i<<" "<<charHash[i]<<endl;
                if(charHash[i]==2)//using 2 for 1 as 1 is already used for + and - both so using 2 for 1 as 1 is not used for + and - both
                {
                    chk=0;
                    break;
                }
                charHash[i]=1;
            }
            consider=j-1;//move next j-1?
            // j-=1;
        }
        else
        {
            if(charHash[j-1]==1 || j<2)//this check for 0 as 0 can't be the first element and 0 can't be the last element if 1 is not present
            {
                chk=0;
                break;
            }
            charHash[j-1]=2;//already used
        }
    }
    return chk;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	string s;
        cin>>s;
        if(sol(s))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}