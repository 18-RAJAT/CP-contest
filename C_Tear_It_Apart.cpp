#include<bits/stdc++.h>
using namespace std;



void sol()
{
    string s;
    cin>>s;
    
    int ans=200005;
    for(auto i='a';i<='z';++i)
    {
        vector<int>smallest;
        for(int j=0;j<s.size();++j)
        {
            if(i!=s[j])
            {
                smallest.push_back(j);
            }
        }

        auto letterSelect=[&](int x)->void
        {
            int k=0;
            int consist=k+x;
            while(k+x<smallest.size() and smallest[consist]==k+smallest[x])
            {
                k++;
            }
        };
        int mx=0;
        for(int j=0;j<smallest.size();++j)
        {
            int k=0;
            while(j+k<smallest.size() and smallest[j+k]==smallest[j]+k)
            {
                k++;
            }
            
            letterSelect(j);

            int selected=log2(k)+1;
            mx=max(mx,selected);
            // j+=k--;
            j+=k-1;
        }
        ans=min(ans,mx);
    }
    cout<<ans<<"\n";
}
int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        sol();
    }
    return 0;
}