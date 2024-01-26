#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5
//     Rows are often numbered from top to bottom, starting from 0 at the top.
//     Columns are often numbered from left to right, starting from 0 on the left.

// With this convention, moving "up" means decreasing the row index, and moving "down" means increasing the row index.
int dRow[] = {-1, 0, 0, 1};
int dCol[] = {0, 1, -1, 0};

bool cellisvisited(bool vis[][COL], int row, int col, int grid[][COL])
{
    if (row < 0 || col < 0 || row >= ROW || col >= COL)
        return false;

    if (vis[row][col] || grid[row][col] == -1)
        return false;

    return true;
}

void DFS(int grid[][COL], bool vis[][COL], pair<int, int> start, pair<int, int> goal)
{
    stack<pair<int, int>> s;

    s.push(start);

    vis[start.first][start.second] = true;

    vector<int> cellNumbers;

    while (!s.empty())
    {
        pair<int, int> cell = s.top();
        int x = cell.first;
        int y = cell.second;

        int cellNumber = x * COL + y + 1;
        cellNumbers.push_back(cellNumber);

        if (x == goal.first && y == goal.second)
        {
            cout << "\nThe Goal is reached\n";
            cout << "Shortest path: ";
            for (int i : cellNumbers)
            {
                cout << i << " ";
            }
            cout << endl;
            return;
        }

        s.pop();

        for (int i = 3; i >= 0; i--)
        {
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (cellisvisited(vis, adjx, adjy, grid))
            {
                s.push({adjx, adjy});
                vis[adjx][adjy] = true;
            }
        }
    }

    cout << "\nThe Goal is not reached\n";
}

int main()
{
    int grid[ROW][COL] = {
        {-1, 2, 3, -1, -1},
        {6, 7, -1, -1, -1},
        {11, 12, 13, -1, -1},
        {-1, 17, 18, 19, -1},
        {-1, 22, -1, -1, 25}};

    pair<int, int> start = {3, 1};
    pair<int, int> goal = {0, 1};

    bool vis[ROW][COL];
    memset(vis, false, sizeof vis);

    DFS(grid, vis, start, goal);

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define ROW 5
// #define COL 5

// // priority (up, right, left, down)
// int dRow[] = {-1, 0, 0, 1};
// int dCol[] = {0, 1, -1, 0};

// // if a cell is be visited or not
// bool cellisvisited(bool vis[][COL], int row, int col, int grid[][COL])
// {
    
//     if (row < 0 || col < 0 || row >= ROW || col >= COL)
//         return false;

//     // If cell is already visited or is an obstacle
//     if (vis[row][col] || grid[row][col] == -1)
//         return false;

    
//     return true;
// }



// void DFS(int grid[][COL], bool vis[][COL], pair<int, int> start, pair<int, int> goal)
// {
   
//     stack<pair<int, int>> s;

    
//     s.push(start);

//     vis[start.first][start.second] = true;

//     while (!s.empty())
//     {
//         pair<int, int> cell = s.top();
//         int x = cell.first;
//         int y = cell.second;

//         cout << grid[x][y] << " ";

//         if (x == goal.first && y == goal.second)
//         {
//             cout << "\nThe Goal is reached\n";
//             return;
//         }

//         s.pop();

//         for (int i = 3; i >= 0; i--)
//         {
//             int adjx = x + dRow[i];
//             int adjy = y + dCol[i];

//             if (cellisvisited(vis, adjx, adjy, grid))
//             {
//                 s.push({adjx, adjy});
//                 vis[adjx][adjy] = true;
//             }
//         }
//     }

//     cout << "\nThe Goal is not reached\n";
// }

// int main()
// {
//     int grid[ROW][COL] = {
//         {-1, 2, 3, -1, -1},
//         {6, 7, -1, -1, -1},
//         {11, 12, 13, -1, -1},
//         {-1, 17, 18, 19, -1},
//         {-1, 22, -1, -1, 25}};

//     // Start point
//     pair<int, int> start = {3, 1};

//     //  goal point
//     pair<int, int> goal = {0, 1};

//     bool vis[ROW][COL];
//     memset(vis, false, sizeof vis);

//     DFS(grid, vis, start, goal);

//     return 0;
// }
