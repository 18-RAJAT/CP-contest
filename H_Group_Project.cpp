#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
template<int mod>
struct mod_int
{
    int x;
    mod_int():x(0){}
    mod_int(int y):x(y>=0?y%mod:(y%mod+mod)%mod){}
    mod_int inv() const
    {
        int a=x,b=mod,u=1,v=0;
        while(b)
        {
            int t=a/b;
            a-=t*b;
            swap(a,b);
            u-=t*v;
            swap(u,v);
        }
        return mod_int(u);
    }
    mod_int operator-() const
    {
        return mod_int(-x);
    }
    mod_int operator+(const mod_int& y) const
    {
        return mod_int(x+y.x);
    }
    mod_int operator-(const mod_int& y) const
    {
        return mod_int(x-y.x);
    }
    mod_int operator*(const mod_int& y) const
    {
        return mod_int(x*y.x);
    }
    mod_int operator/(const mod_int& y) const
    {
        return *this*y.inv();
    }
    mod_int& operator+=(const mod_int& y)
    {
        x+=y.x;
        if(x>=mod) x-=mod;
        return *this;
    }
    mod_int& operator-=(const mod_int& y)
    {
        x-=y.x;
        if(x<0) x+=mod;
        return *this;
    }
    mod_int& operator*=(const mod_int& y)
    {
        x=x*y.x%mod;
        return *this;
    }
    mod_int& operator/=(const mod_int& y)
    {
        return *this*=y.inv();
    }
    bool operator==(const mod_int& y) const
    {
        return x==y.x;
    }
    bool operator!=(const mod_int& y) const
    {
        return x!=y.x;
    }
    mod_int pow(int n) const
    {
        mod_int res=1,t=*this;
        while(n)
        {
            if(n&1) res*=t;
            t*=t;
            n>>=1;
        }
        return res;
    }
    friend ostream& operator<<(ostream& os,const mod_int& y)
    {
        return os<<y.x;
    }
    friend istream& operator>>(istream& is,mod_int& y)
    {
        int t;
        is>>t;
        y=mod_int(t);
        return is;
    }
};
void sol()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int x=stoll(a.substr(7,3));
    int y=stoll(b.substr(7,3));
    function<int(int,int)>roll=[&](int x,int y)->int{return (x>=0?(x+y-1)/y:x/y);};
    if(x>y) swap(x,y);
    int p=y-x;
    mod_int<Mod> ans=0;
    for(int i=p;i<n;++i)
    {
        if(roll(x,i+1)==roll(y,i+1)) ans+=1;
    }
    cout<<ans/n;
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