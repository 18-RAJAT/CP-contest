
#include <bits/stdc++.h>
using namespace std;
 
#define fio                  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll                    long long int


int main(){
    fio;
    ll T=1;
    cin>>T;
    for(int test=1;test<=T;test++){

        ll rs, rh;
        cin>>rs>>rh;

        ll n;
        cin>>n;

        ll t1,t2;
        vector<double> a1(n);
        for(int i=0;i<n;i++){
            cin>>t1>>t2;
            a1[i] = (double)sqrt(t1*t1 + t2*t2);
        }
        sort(a1.begin(), a1.end());

        ll m;
        cin>>m;
        vector<double> a2(m);
        for(int i=0;i<m;i++){
            cin>>t1>>t2;
            a2[i] = (double)sqrt(t1*t1 + t2*t2);
        }
        sort(a2.begin(), a2.end());

        ll temp = 0;
        ll a=0, b=0;

        if(m!=0 && n!=0){
            if(a1[0]<a2[0]){
                
                while(temp<n && a1[temp] < a2[0] &&  a1[temp]-rs<=rh){
                    temp++;
                    a++;
                }

            } else {                  
                
                while(temp<m && a2[temp]<a1[0] &&  a2[temp]-rs<=rh){
                    temp++;
                    b++;
                }

            }
        } else {

            while(n!=0 && temp<n &&  a1[temp]-rs <= rh){
                temp++;
                a++;
            }

            while(m!=0 && temp<m && a2[temp]-rs <= rh){
                temp++;
                b++;
            }
        }
        
        cout<<"CASE #"<<test<<": "<<a<<" "<<b;

        
 
        cout<<"\n";
    }
    
    return 0;
}