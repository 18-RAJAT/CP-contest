    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        long long n,k;
        cin>>n>>k;

        vector<long long>a(n,0);
        string s;
        for(long long i=0;i<n;++i)
        {
            cin>>a[i];
        }
        cin>>s;
        a.push_back(0);
        s+='#';

        long long ans=0;
        priority_queue<long long>pq;

        pq.push(a[0]);
        for(long long i=1;i<=n;++i)
        {
            if(s[i]!=s[i-1])
            {
                long long temp=k;
                while(not pq.empty() and temp--)
                {
                    ans+=pq.top();
                    pq.pop();
                }
                // pq.pop();
                while(not pq.empty())
                {
                    pq.pop();
                }
            }
            pq.push(a[i]);
        }
        // cout<<pq.top()<<"\n";
        cout<<ans<<"\n";
        return (0-0);
    }