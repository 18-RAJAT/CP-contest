#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        set<string>st;
        for(int i=0;i<n;i++)
        {
            st.insert(s.substr(i,2));
        }
        cout<<st.size()-1<<"\n";
    }
}