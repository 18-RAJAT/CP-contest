#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    //pos combination!!
    vector<string>str{"ABC","ACB","BAC","BCA","CAB","CBA"};
    for(int i=0;i<6;++i)
    {
        if(s.find(str[i])!=string::npos)
        {
            cout<<"Yes"<<"\n";
            return 0;
        }
    }
    cout<<"No"<<"\n";
    return 0;
}