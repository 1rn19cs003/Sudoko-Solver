#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <unordered_map>
#include <list>
#include <deque>
#include <array>
#include <stack>
#include <forward_list>
#include <queue>
#include <set>
#include <unordered_set>
#include <iterator>
#include <cmath>
#include <ios>
#include <iostream>
#include <istream>
#include <fstream>
#include <cstdio>
// using namespace std::chrono;
using namespace std;
void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> row, vector<map<int, int>> col)
{
    if (r == 9)
    {
        for (auto it : a)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (c == 9)
    {
        helper(r + 1, 0, a, mp, row, col);
        return;
    }
    if (a[r][c] != '.')
    {
        helper(r, c + 1, a, mp, row, col);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        int rw = r / 3, cl = c / 3;
        if (!mp[{rw, cl}][i] && !row[r][i] && !col[c][i])
        {
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i + '0';
            helper(r, c + 1, a, mp, row, col);
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';
        }
    }
}
void solveSoduku(vector<vector<char>> &a)
{
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] != '.')
            {
                mp[{i / 3, j / 3}][a[i][j] - '0'] = 1;
                row[i][a[i][j] - '0'] = 1;
                col[j][a[i][j] - '0'] = 1;
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char>> soduku = {
        {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
        {'1', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '4', '3', '.', '2', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
        {'.', '.', '.', '5', '.', '9', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '4', '1', '8'},
        {'.', '.', '.', '.', '8', '1', '.', '.', '.'},
        {'.', '.', '2', '.', '.', '.', '.', '5', '.'},
        {'.', '4', '.', '.', '.', '.', '3', '.', '.'}};
    // auto start = high_resolution_clock::now();
    solveSoduku(soduku);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " ms" << endl;
}