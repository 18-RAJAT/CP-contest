#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int count=0,ok=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]!=i+1)
        {
            ok=1;
            break;
        }
    }
    if(ok==0)
    {
        cout<<0;
        exit(0);
    }
    vector<vector<int>>v(n);
    while(true)
    {
        int pos=-1;
        for(int i=0;i<n;++i)
        {
            if(a[i]==1)
            {
                pos=i;
                break;
            }
        }
        bool flag=false;
        for(int i=pos;i<n-1;++i)
        {
            if(a[i+1]-a[i]!=1)
            {
                flag=true;
                break;
            }
        }
        if(flag!=1)
        {
            for(int i=0;i<pos-1;++i)
            {
                if((a[i+1]-a[i])!=1)
                {
                    flag=true;
                    break;
                }
            }
        }
        if(flag==false)
        {
            v[count].push_back(pos);
            v[count].push_back(n-pos);
            count++;
            break;
        }
        for(int i=0;i<n-1;++i)
        {
            if(a[i]!=i+1)
            {
                pos=i;
                break;
            }
        }
        int get=-1;
        for(int i=0;i<n;++i)
        {
            if(a[i]==a[pos]-1)
            {
                get=i;
                break;
            }
        }
        v[count].push_back(pos);
        v[count].push_back(get-pos);
        v[count].push_back(1);
        v[count].push_back(n-get-1);

        vector<int>array;
        int pref=0;
        for(int i=v[count].size()-1;i>=0;--i)
        {
            for(int j=n-(pref+v[count][i]);j<n-pref;++j)
            {
                array.push_back(a[j]);
            }
            pref+=v[count][i];
        }
        for(int i=0;i<n;++i)
        {
            a[i]=array[i];
        }
        count++;
    }
    cout<<count<<"\n";
    for(int i=0;i,count;++i)
    {
        int ans=0;
        for(int j=0;j<v[i].size();++j)
        {
            if(v[i][j]!=0)
            {
                ans++;
            }
        }
        cout<<ans<<" ";
        for(int j=0;j<v[i].size();++j)
        {
            if(v[i][j]!=0)
            {
                cout<<v[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}