#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n),d(m),f(k);
    for(int i=0;i<a.size();++i)cin>>a[i];
    for(int i=0;i<d.size();++i)cin>>d[i];
    for(int i=0;i<f.size();++i)cin>>f[i];
    // auto imbalance=[&](vector<int>& imb_arr)->int
    // {
    		// int diff=0;
    		// for(int i=1;i<imb_arr.size();++i)diff=max(diff,imb_arr[i]-imb_arr[i-1]);
    		// return diff;
    // };
    sort(a.begin(),a.end());sort(d.begin(),d.end());sort(f.begin(),f.end());
    // int init_imbalance=imbalance(a);
    // set<int>possible_complexity;
    // for(int i=0;i<m;++i)
    // {
    		// for(int j=0;j<k;++j)
    		// {
    			// possible_complexity.insert(d[i]+f[j]);
    		// }
    // }
    // int min_imbalance=init_imbalance;
    int left=0,right=0,first_complexity=0,second_complexity=0;
    for(int i=1;i<n;++i)
    {
    	// int right=a[i],left=a[i-1];
    	// int current_gap=right-left;
    	//minimizing the current gap
    	if((a[i]-a[i-1])>first_complexity)
    	{
            second_complexity=first_complexity;
            first_complexity=(a[i]-a[i-1]);
            left=a[i-1];right=a[i];
        }
        else if((a[i]-a[i-1])>second_complexity)
        {
             second_complexity=(a[i]-a[i-1]);
        }
    }
    // for(auto& it:d)
    // {
    // 	int lb=lower_bound(f.begin(),f.end(),left-it)-f.begin();
	// 	int ub=upper_bound(f.begin(),f.end(),right-it)-f.begin();     		
    // 	if(lb<k)
    // 	{
	// 		int new_complexity=it+f[lb];
    // 		if(new_complexity<right && new_complexity>left)
    // 		{
    // 			int new_gap=max(new_complexity-left,right-new_complexity);
    // 			min_imbalance=min(min_imbalance,max(new_gap,current_gap));
    // 		}
	// 	}
    // 	if(ub<k)
    // 	{
	// 		int new_complexity=it+f[ub];
    // 		if(new_complexity<right && new_complexity>left)
    // 		{
    // 			int new_gap=max(new_complexity-left,right-new_complexity);
    // 			min_imbalance=min(min_imbalance,max(new_gap,current_gap));
    // 		}
    //     }
    // }
    int count=0;
	for(int i=1;i<n;++i)
	{
	    if((a[i]-a[i-1])==first_complexity)
	    {
	    	count++;
	    }
	}
	if(count>=2)
	{
	    cout<<first_complexity<<endl;
	    return;
	}
	int mid=(left+right)/2;
	int possible_complexity=first_complexity;
	for(int i=0;i<m;++i)
	{
	    auto index=upper_bound(f.begin(),f.end(),mid-d[i]);

        if(index!=f.end())
        {
            int new_complexity=d[i]+*index;
            if(new_complexity>left && new_complexity<right)
            {
                int new_gap=max(new_complexity-left,right-new_complexity);
                possible_complexity=min(possible_complexity,new_gap);
            }
        }
        if(index!=f.begin())
        {
            index--;
            int new_complexity=d[i]+*index;
            if(new_complexity>left && new_complexity<right)
            {
                int new_gap=max(new_complexity-left,right-new_complexity);
                possible_complexity=min(possible_complexity,new_gap);
            }
        }
	    // int imbalance_check1=1e9;
	    // int imbalance_check2=1e9;
	    // if(index!=k && (d[i]+f[index])>=left && (d[i]+f[index])<=right)
        // {
	    //     imbalance_check1=max(0LL,max(d[i]+f[index]-left,right-d[i]-f[index]));
	    // }
	    // if(index>0 && (d[i]+f[index-1])>=left && (d[i]+f[index-1])<=right)
        // {
	    //     imbalance_check2=max(0LL,max(d[i]+f[index-1]-left,right-d[i]-f[index-1]));
	    // }
	    // int imbalance_possible=min(imbalance_check2,imbalance_check1);
	    // possible_complexity=min(possible_complexity,imbalance_possible);
	    
	}
	int imbalance=max(possible_complexity,second_complexity);
	cout<<imbalance<<endl;
    //new complexity
    // for(auto& it:possible_complexity)
    // {
    	// vector<int>temp=a;
    	// temp.push_back(it);
    	// sort(temp.begin(),temp.end());
    	// int new_imbalance=imbalance(temp);
    	// min_imbalance=min(min_imbalance,new_imbalance);
    // }
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