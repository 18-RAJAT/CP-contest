#include<bits/stdc++.h>
using namespace std;

const int N=100001;
class sol
{
    public:
    int n,k;
    int arr[N];
    int chk[N];
    int count;
    
    public:
    sol():n(0),k(0),count(0){}

    void init()
    {
        chk[0]=0;
        for(int i=1;;++i)
        {
            chk[i]=chk[i-1]+i;
            count+=1;

            if(chk[i]>=1000001)
            {
                break;
            }
        }
    }
    void solve()
    {
        cin>>n>>k;
        // if(n==k)
        // {
        //     cout<<0<<"\n";
        //     return;
        // }
        init();
        auto print=[this]()
        {
            for(int i=1;i<=count;++i)
            {
                if(k<=chk[i] and k+n-i==chk[i])
                {
                    cout<<n-i;
                    break;
                }
            }
        };
        print();
    }
    ~sol()
    {
        // delete[] arr;
        // delete[] chk;
        memset(arr,0,sizeof(arr));
        memset(chk,0,sizeof(chk));
        count=0;
        n=0;
        k=0;
    }
};

int main()
{
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        sol *s=new sol();
        s->solve();
        delete s;
    }
    return 0;
}