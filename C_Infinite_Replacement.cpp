#include<bits/stdc++.h>
using namespace std;

class sol
{
    private:
    string a,b;
    public:
    sol(){}
    sol(const string& a,const string& b):a(a),b(b){}

    void solve()
    {
        long long int replace=0;
        for(long long int i=0;i<b.size();++i)
        {
            if(b[i]=='a')
            {
                replace=1;
                break;
            }
        }
        if(replace==1 or a==b)
        {
            cout<<((b.size()==1)?1:-1)<<"\n";
        }
        else
        {
            long long int tmp=1;
            // for(long long int i=0;i<a.size()-1;++i)
            long long int szA=a.size();
            while(szA-->0)
            {
                tmp*=2;
            }
            cout<<tmp<<"\n";
        }
    }
};

int main()
{
    long long int tc;
    cin>>tc;
    while(tc-->0)
    {
        string a,b;
        cin>>a>>b;
        sol s(a,b);
        s.solve();
    }
    return 0;
}