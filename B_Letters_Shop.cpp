#include<bits/stdc++.h>
using namespace std;
int main()
{
    int freq[200005][26]={};
    function<bool(int[],int)>check=[&](int hash[],int n)->bool
    {
        // int freq[26]={};
        // for(int i=0;i<n;++i)
        // {
        //     freq[s[i]-'a']++;
        // }
        for(int i=0;i<26;++i)
        {
            if(freq[n-1][i]<hash[i])
            {
                return false;
            }
        }
        return true;
    };

    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;++i)
    {
        freq[i][s[i]-'a']++;
        if(i)
        {
            for(int j=0;j<26;++j)
            {
                freq[i][j]+=freq[i-1][j];
            }
        }
    }
    // cout<<freq[n-1][0]<<"\n";
    int t;cin>>t;
    while(t--)
    {
        string str;cin>>str;
        int hash[26]={};
        int sza=str.size();
        for(int i=0;i<sza;++i)hash[str[i]-'a']++;
        int low(1),high(n);

        // function<void(int,int)>swap=[&](int low,int high)->void
        // {
        //     int temp=hash[low];
        //     hash[low]=hash[high];
        //     hash[high]=temp;
        // };

        int ans(0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(hash,mid))
            {
                ans=mid;
                high=mid-1;
            }
            // else if(swap(mid,high))
            // {
                // low=mid+1;
            //     ans=0;
            // }
            else
            {
                low=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}