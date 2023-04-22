#include<bits/stdc++.h>
using namespace std;

int main()
{
    int lamps;
    cin>>lamps;

    string garland;
    cin>>garland;

    int contains=200001;
    int color=0;
    string colors[]={"RGB","RBG","GBR","GRB","BRG","BGR"};
    int possiblePatterns=6;
    for(int i=0;i<possiblePatterns;++i)
    {
        int count=0;
        for(int j=0;j<lamps;++j)
        {
            if(garland[j]!=colors[i][j%3])
            {
                count++;
            }
        }
        if(count<contains)
        {
            contains=count;
            color=i;
        }
    }
    // auto it=unique(garland.begin(),garland.end());

    auto minimumNumberOfRecolors=[&](string s)->void
    {
        for(int i=0;i<lamps;++i)
        {
            cout<<s[i%3];
        }
        cout<<"\n";
    };

    cout<<contains<<"\n";
    minimumNumberOfRecolors(colors[color]);
}