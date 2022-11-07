#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
void GO_FAST()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int main()
{
GO_FAST();
   ll h;   cin>>h;
   vector<char>q={'0' , '1' , '2' , '3' , '4' , '5' ,'6' ,'7' ,'8' ,'9' , '#' , '@' , '*' , '&' };
   for(int T=1;T<=h;++T){
           int n;   cin>>n;
           string s;   cin>>s;
           bool a=0,b=0,z= ( n >= 7 ) ,u=0 , c=0;
           for(int i=0;i<n;++i){
                bool k=0;
     for(int j=0;j<q.size() ; ++j ){
         if(s[i]==q[j]){
           if(j <= 9 ) u=1;
        else c=1;  
        k=1;
         }
          }   
          if(k==0){
        if(isupper(s[i]))a=1;
     else if(islower(s[i]))b=1;
     }
     
      }
           if(a  and  b  and  c  and  u  and  z)cout<<"Case #"<<T<<": "<<s<<endl;
           else{
             if(!a)s+="A";
       if(!b)s+="a";
       if(!u)s+="1";
       if(!c)s+="*";  
       while(s.size()<7)s+='1';
       cout<<"Case #"<<T<<": "<<s<<endl;
           }
     }
  }