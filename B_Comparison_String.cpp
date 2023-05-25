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
        int count=1;
        int maximum=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                count++;
            }
            else
            {
                maximum=max<int>(maximum,count);
                count=1;
            }
        }
        maximum=max<int>(maximum,count);
        maximum++;
        cout<<maximum<<"\n";
    }
    return 0;
}