#include<bits/stdc++.h>
using namespace std;

void sol()
{
    string s,h;
    cin>>s>>h;
    sort(s.begin(),s.end());
    for(int i=0;i<h.size();++i)
    {
        string polycarp;

        for(int j=i;j<i+s.size();++j)
        {
            polycarp.push_back(h[j]);
            sort(polycarp.begin(),polycarp.end());
        }
        if(polycarp==s)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}