#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<string>ans;
void sol()
{
    int n;
    cin>>n;
    string s="";
    while(n)
    {
        (n%2?s.push_back('1'):s.push_back('0')),n/=2;
    }
    int temp=0,flag=0;
    for(int i=0;i<=(int)s.size()-1;++i)
    {
        if(s[i]=='1')
        {
            string res="";
            temp++;
            for(int j=0;j<=i-1;++j)
            {
                res+='1';
            }
            ans.push_back(res);
            for(int j=i+1;j<=(int)s.size()-1;++j)
            {
                if(s[j]=='1')
                {
                    s[j]='0';
                }
                else
                {
                    temp++;
                    s[j]='1';
                    break;
                }
            }
        }
    }
    cout<<temp<<endl;
    for(int i=0;i<=(int)ans.size()-1;++i)
    {
        cout<<ans[i].size()<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}