#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

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

void ShortPath(vector<pair<int, int>> &path, int grid[][COL])
{
    cout << "Shortest path:";
    for (const auto &point : path)
    {
        int cellNumber = point.first * COL + point.second + 1;
        cout << " " << cellNumber;
    }
    cout << endl;
}

void BFS(int grid[][COL], bool vis[][COL], pair<int, int> start, pair<int, int> goal)
{
    //first element added to the queue will be the first one to be removed
    queue<vector<pair<int, int>>> q;
//    Creates the initial path with only the starting point.
    vector<pair<int, int>> initialPath = {start};
    q.push(initialPath);
    //    Marks the starting point as visited.
    vis[start.first][start.second] = true;
//    Loop runs as long as the queue is not empty.
    while (!q.empty())
    {//    Retrieves the front path from the queue.
        vector<pair<int, int>> path = q.front();
        //    Gets the current position from the back of the path.
        pair<int, int> current = path.back();
        //    Dequeues the front path.
        q.pop();

        int x = current.first;
        int y = current.second;
//    Checks if the current position is equal to the goal.
    //If true, prints the shortest path using the ShortPath function and returns from the function.
        if (x == goal.first && y == goal.second)
        {
            cout << "\nThe Goal is reached\n";
            ShortPath(path, grid);
            return;
        }
//    Iterates over the four possible directions.
        for (int i = 0; i < 4; i++)
        {
            //    Calculates the x-coordinate of the adjacent cell.
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (cellisvisited(vis, adjx, adjy, grid))
            {
                vector<pair<int, int>> newPath = path;
                newPath.push_back({adjx, adjy});
                q.push(newPath);
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

    BFS(grid, vis, start, goal);

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define ROW 5
// #define COL 5

// //  priority (up, right, left, down)
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

// void BFS(int grid[][COL], bool vis[][COL], pair<int, int> start, pair<int, int> goal)
// {
//     queue<pair<int, int>> q;

//     q.push(start);
//     vis[start.first][start.second] = true;

//     while (!q.empty())
//     {
//         pair<int, int> cell = q.front();
//         int x = cell.first;
//         int y = cell.second;

//         cout << grid[x][y] << " ";

//         q.pop();

//         if (x == goal.first && y == goal.second)
//         {
//             cout << "\nThe Goal is reached\n";
//             return;
//         }

//         for (int i = 0; i < 4; i++)
//         {
//             int adjx = x + dRow[i];
//             int adjy = y + dCol[i];

//             if (cellisvisited(vis, adjx, adjy, grid))
//             {
//                 q.push({adjx, adjy});
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

//     // goal point
//     pair<int, int> goal = {0, 1};

    
//     bool vis[ROW][COL];
//     memset(vis, false, sizeof vis);

//     BFS(grid, vis, start, goal);

//     return 0;
// }