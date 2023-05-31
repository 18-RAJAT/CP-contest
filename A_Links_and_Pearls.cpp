#include<bits/stdc++.h>
using namespace std;
int main()
{
    int links,pearls;
    string s;
    cin>>s;
    links=count(s.begin(),s.end(),'-');
    pearls=s.size()-links;
    cout<<((pearls<=1 or links%pearls==0)?"YES":"NO")<<"\n";
}