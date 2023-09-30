#include<bits/stdc++.h>
using namespace std;
#define int long long
struct line
{
    int a,b;
    int get(int x)
    {
        // cout<<a<<" "<<b<<" "<<x<<endl;
        return a*x+b;//returns the value of the line at x (y=ax+b)
    }
};
struct ConvexHull
{
    int num;
    line* hull;
    ConvexHull(int sza)
    {
        hull=new line[sza+1001];
        num=0;
    }
    bool lineBar(int Curr,int Prev,int Next)//Curr is the middle line
    {
        line c=hull[Curr],n=hull[Next],p=hull[Prev];//c is the middle line and n is the next line and p is the previous line
        return (c.b-n.b)*(c.a-p.a)<=(p.b-c.b)*(n.a-c.a);//returns true if the intersection of c and n is to the right of the intersection of c and p
    }
    void addLine(int m,int c)
    {
        hull[num++]=(line){m,c};
        while(num>2 && lineBar(num-2,num-3,num-1))//while the intersection of the previous line and the next line is to the right of the intersection of the previous line and the current line
        {
            hull[num-2]=hull[num-1];
            num--;
            // cout<<"Num: "<<num<<endl;
        }
    }
    //returns the maximum value of the lines at x
    int query(int x)
    {
        int l=-1,r=num-1;
        while(r-l>1)
        {
            int m=l+(r-l)/2;
            if(hull[m].get(x)<=hull[m+1].get(x))//if the value of the line at x is less than the value of the next line at x
            {
                l=m;
            }
            else
            {
                r=m;
            }
        }
        return hull[r].get(x);
    }
};
void sol()
{
    int n;
    cin>>n;
    ConvexHull Hull(n);
    vector<int> a(n+1);
    int ans=0,secondHalf=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=i*a[i];
    }
    vector<int>sum(n,0);
    sum.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    Hull.num=0;
    for(int l=n-1;l>=1;l--)//l is the leftmost element in the second half
    {
        // cout<<l<<endl;
        Hull.addLine(-(l+1),-sum[l+1]);//the slope is -(l+1) and the y-intercept is -sum[l+1]
        
        secondHalf=max(secondHalf,Hull.query(-a[l])+sum[l]-l*a[l]);//the value of the line at -a[l] is the value of the line at a[l] but with the slope and y-intercept negated

        // cout<<secondHalf<<endl;
    }
    Hull.num=0;
    for(int r=2;r<=n;r++)//r is the rightmost element in the first half
    {
        Hull.addLine(r-1,-sum[r-2]);//the slope is r-1 and the y-intercept is -sum[r-2]

        secondHalf=max(secondHalf,Hull.query(a[r])+sum[r-1]-r*a[r]);//the value of the line at a[r] is the value of the line at -a[r] but with the slope and y-intercept negated

        // cout<<secondHalf<<endl;
    }
    cout<<ans+secondHalf<<endl;
}
signed main()
{
    sol();
    return 0;
}