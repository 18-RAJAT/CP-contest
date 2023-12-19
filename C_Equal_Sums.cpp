#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[2000005];
string check(int n)
{
    string s;
    int ct=-1;
    while(n)
    {
        //insert(pos,len,char)
        s.insert(++ct,1,(n%10)+48);
        n/=10;
    }
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    return s;
}
void sol()
{
    int k;
    cin>>k;
    vector<int>arr[k],chk;
    for(int i=0;i<k;++i)
    {
        int n;
        cin>>n;
        chk.push_back(n);
        int s=0;
        for(int j=0;j<n;++j)
        {
            int x;
            cin>>x;
            arr[i].push_back(x);
            s+=arr[i][j];
        }
        ans[i]=s;
    }
    unordered_map<int,string>mp;
    for(int i=0;i<k;++i)
    {
        unordered_map<int,string>temp=mp;
        for(int j=0;j<chk[i];++j)
        {
            string &recur=mp[ans[i]-arr[i][j]];
            for(int k=0;k<recur.size();++k)
            {
                if(recur[k]>check(i+1)[k])
                {
                    recur=check(i+1);
                    break;
                }
                else if(recur[k]<check(i+1)[k])
                {
                    break;
                }
            }
            if(temp.count(ans[i]-arr[i][j])==0 || temp[ans[i]-arr[i][j]]>recur || recur=="")
            {
                recur=check(i+1)+" "+check(j+1);
            }
            else
            {
                cout<<"YES"<<endl;
                cout<<recur<<endl;
                cout<<check(i+1)<<" "<<check(j+1)<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}
signed main()
{
    sol();
    return 0;
}