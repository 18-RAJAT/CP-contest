#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int diffFirst=0;
    // reverse(s1.begin(),s1.end());
    for(int i=0;i<n;++i)
    {
        if(s1[i]!=s2[i])
        {
            diffFirst++;
        }
    }
    int diffSecond=0;
    reverse(s2.begin(),s2.end());
    for(int i=0;i<n;++i)
    {
        if(s1[i]!=s2[i])
        {
            diffSecond++;
        }
    }
    int chkFirst=2*diffFirst;
    int chkSecond=2*diffSecond;
    if(diffFirst==0)
    {
        cout<<"0"<<"\n";
        return;
    }
    else if(diffSecond==0)
    {
        cout<<"2"<<"\n";
        return;
    }
    if(diffFirst%2!=0)
    {
        chkFirst--;
    }
    if(diffSecond%2==0)
    {
        chkSecond--;
    }
    // cout<<chkFirst<<" "<<chkSecond<<"\n";
    cout<<min<int>(chkFirst,chkSecond)<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}