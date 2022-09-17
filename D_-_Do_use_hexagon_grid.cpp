#include<iostream>
#include<vector>
using namespace std;
void connected(vector<vector<char>>& v, vector<vector<bool>>& visited, int i, int j) {
    if (i < 0 or i >= v.size() or j < 0 or j >= v[0].size() or v[i][j] == '0' or visited[i][j] == true) {
        return;
    }
    visited[i][j] = true;
    connected(v, visited, i + 1, j);
    connected(v, visited, i, j + 1);
    connected(v, visited, i, j - 1);
    connected(v, visited, i - 1, j);
}
int numIslands(vector<vector<char>>& v) {
    int count = 0;
    vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == '1' && visited[i][j] == false) {
                connected(v, visited, i, j);
                count++;
            }
        }
    }
    return count;
}
int main() {
    vector<vector<char>> v(2001, vector<char>(2001, '0'));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[1000 - x][1000 - y] = '1';
    }
    cout << numIslands(v);
}