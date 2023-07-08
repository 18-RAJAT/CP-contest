#include<bits/stdc++.h>
using namespace std;

void sol()
{
    string s1,s2,s3;
    auto chk=[&](char c1,char c2,char c3,char k)->bool
    {
        if(c1==k&&c2==k&&c3==k)
        {
            return true;
        }
        return false;
    };
    auto calc=[&](char x)->bool
    {
        if(chk(s1[0],s1[1],s1[2],x))
        {
            return true;
        }
        if(chk(s2[0],s2[1],s2[2],x))
        {
            return true;
        }
        if(chk(s3[0],s3[1],s3[2],x))
        {
            return true;
        }


        if(chk(s1[0],s2[0],s3[0],x))
        {
            return true;
        }
        if(chk(s1[1],s2[1],s3[1],x))
        {
            return true;
        }
        if(chk(s1[2],s2[2],s3[2],x))
        {
            return true;
        }

        if(chk(s1[0],s2[1],s3[2],x))
        {
            return true;
        }
        if(chk(s1[2],s2[1],s3[0],x))
        {
            return true;
        }
        return false;
    };
    cin>>s1>>s2>>s3;
    if(calc('X'))
    {
        cout<<"X\n";
        return;
    }
    if(calc('O'))
    {
        cout<<"O\n";
        return;
    }
    if(calc('+'))
    {
        cout<<"+\n";
        return;
    }
    cout<<"DRAW\n";
}
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}