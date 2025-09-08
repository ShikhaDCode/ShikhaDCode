#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

// Directions for adjacent cells (up, down, left, right)
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// Function to perform BFS for flood fill
void floodFill(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, char owner, int& gridCount) {
    int n = grid.size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    gridCount++;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            // Check bounds and ownership
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && grid[nx][ny] == owner) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                gridCount++;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    
    // Read the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Initialize data structures
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int zonesR = 0, zonesG = 0, zonesB = 0;
    int gridsR = 0, gridsG = 0, gridsB = 0;

    // Traverse the grid to calculate zones and grid counts
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                char owner = grid[i][j];
                int gridCount = 0;

                // Perform flood fill
                floodFill(grid, visited, i, j, owner, gridCount);

                // Update counts based on owner
                if (owner == 'R') {
                    zonesR++;
                    gridsR += gridCount;
                } else if (owner == 'G') {
                    zonesG++;
                    gridsG += gridCount;
                } else if (owner == 'B') {
                    zonesB++;
                    gridsB += gridCount;
                }
            }
        }
    }

    // Determine the owner to purchase from
    char bestOwner = 'R';
    int bestZones = zonesR;
    int bestGrids = gridsR;

    // Compare with Green Lantern
    if (zonesG > bestZones || (zonesG == bestZones && gridsG > bestGrids) || (zonesG == bestZones && gridsG == bestGrids && bestOwner != 'R')) {
        bestOwner = 'G';
        bestZones = zonesG;
        bestGrids = gridsG;
    }

    // Compare with Blue Period
    if (zonesB > bestZones || (zonesB == bestZones && gridsB > bestGrids) || (zonesB == bestZones && gridsB == bestGrids && bestOwner == 'G')) {
        bestOwner = 'B';
        bestZones = zonesB;
        bestGrids = gridsB;
    }

    // Output the result
    cout << bestOwner << " " << bestZones << endl;

    return 0;
}
