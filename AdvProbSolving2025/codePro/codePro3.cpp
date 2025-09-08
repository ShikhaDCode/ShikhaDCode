#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Point {
    int x, y;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(const vector<string>& grid, Point start, Point end) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    queue<Point> q;

    q.push(start);
    dist[start.x][start.y] = 0;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] != '*' && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dist[end.x][end.y];
}

int main() {
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    Point start;
    vector<Point> points;

    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (isdigit(grid[i][j])) {
                points.push_back({i, j});
            }
        }
    }

    sort(points.begin(), points.end(), [&grid](Point a, Point b) {
        return grid[a.x][a.y] < grid[b.x][b.y];
    });

    points.insert(points.begin(), start);
    points.push_back(start);

    int n = points.size();
    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                dist[i][j] = bfs(grid, points[i], points[j]);
            }
        }
    }

    vector<int> order(n - 1);
    for (int i = 1; i < n - 1; ++i) {
        order[i - 1] = i;
    }

    int min_distance = INT_MAX;

    do {
        int current_distance = 0;
        int prev = 0;

        for (int i : order) {
            current_distance += dist[prev][i];
            prev = i;
        }

        current_distance += dist[prev][n - 1];
        min_distance = min(min_distance, current_distance);

    } while (next_permutation(order.begin(), order.end()));

    cout << min_distance << endl;

    return 0;
}
