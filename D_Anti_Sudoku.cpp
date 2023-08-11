#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<string>sudoku(9);
        for(int i=0;i<9;++i)
        {
            cin>>sudoku[i];
        }
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(sudoku[i][j]=='1')
                {
                    sudoku[i][j]='9';
                }
            }
        }
        for(int i=0;i<9;++i)
        {
            cout<<sudoku[i]<<"\n";
        }
    }
}