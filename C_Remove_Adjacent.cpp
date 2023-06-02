#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0;
    for(int i='z';i>='a';--i)
    {
        for(int j=0;j<=s.length()-1;++j)
        {
            if(s[j]==i and ((j>=1 and s[j-1]==i-1) or (j<=n and s[j+1]==i-1)))
            {
                s.erase(j,1);
                j=-1;
                count++;
            }
        }
    }
    cout<<count<<"\n";
}