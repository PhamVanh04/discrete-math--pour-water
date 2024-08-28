#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<vector<int>> visited;
void dfs(vector<int> node, int depth = 0, int max_depth = 10) // Thêm tham số depth và max_depth
{
    if (depth > max_depth)
        return;

    visited.insert(node);
    cout << node[0] << " " << node[1] << " " << node[2] << endl;
    for (int i = 0; i < 3; i++)
    {
        int full;
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                full = 10;
            else if (j == 1)
                full = 7;
            else
                full = 4;
            if (i != j && node[i] > 0 && node[j] < full)
            {
                int diff = min(node[i], full - node[j]);
                vector<int> next_node(3);
                next_node[i] = node[i] - diff;
                next_node[j] = node[j] + diff;
                next_node[3 - i - j] = node[3 - i - j];
                if (visited.find(next_node) == visited.end())
                    dfs(next_node, depth + 1, max_depth); // Thêm tham số depth và max_depth
            }
        }
    }
}

int main()
{
    dfs({0, 7, 4});
    return 0;
}