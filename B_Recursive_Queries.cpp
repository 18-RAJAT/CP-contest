#include<bits/stdc++.h>
using namespace std;

class nzp
{
    private:
    vector<int>func;
    vector<vector<int>>cnt;

    int product(int n)
    {
        int res=1;
        while(n!=0)
        {
            int dig=n%10;
            if(dig!=0)
            {
                res*=dig;
            }
            n/=10;
        }
        return res;
    };
    public:
    nzp()
    {
        func.resize(1000001);
        cnt.resize(1000001,vector<int>(10,-1));

        for(int i=1;i<10;++i)
        {
            func[i]=i;
        }
        for(int i=10;i<=1000000;++i)
        {
            // func[i]=func[i-1]*i;
            func[i]=func[product(i)];
            // func[i]=product(i);
        }
        for(int i=1;i<=1000000;++i)
        {
            // for(int j=1;j<10;++j)
            // {
            //     cnt[i][j]=cnt[i-1][j]+cnt[i][j-1];
            // }
            // cnt[i][i]=1;
            cnt[i]=cnt[i-1];
            cnt[i][func[i]-1]++;
        }
    }
    int query(int left,int right,int key)
    {
        left--;
        return cnt[right][key-1]-cnt[left][key-1];
        // cout<<left<<" "<<right;
    }
    ~nzp()
    {
        func.clear();
        cnt.clear();
    }
};

int main()
{
    nzp* obj=new nzp();
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        int lft,ryt,keyP;
        cin>>lft>>ryt>>keyP;
        cout<<obj->query(lft,ryt,keyP)<<"\n";
    }
    delete obj;
    return 0;
}