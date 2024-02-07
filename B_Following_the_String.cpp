#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>Arr;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        Arr.push_back(x);
    }
    string Answer="";
    map<char,int>Map;
    Map.clear();
    int count=0;
    for(int i=0;i<n;++i)
    {
        if(Arr[i]==0)
        {
            Answer+='a'+count;
            Map['a'+count]++;
            count++;
        }
        else
        {
            for(int it=0;it<26;++it)
            {
                if(Map['a'+it]==Arr[i])
                {
                    Answer+='a'+it;
                    Map['a'+it]++;
                    break;
                }
            }
            // Map.clear();
        }
    }
    cout<<Answer<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}