#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int x1, y1, x2, y2;
};

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    long result = (long)x1*y2 + (long)x2*y3 + (long)x3*y1 - ((long)x2*y1 + (long)x3*y2 + (long)x1*y3);
    if (result > 0) return 1;
    else if (result < 0) return -1;
    return 0;
}

bool isOverlab(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2)
        && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2)) {
        return true;
    }
    return false;
}

bool isCross(Line a, Line b) {
    int abc = CCW(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
    int abd = CCW(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
    int cda = CCW(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
    int cdb = CCW(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

    if (abc * abd == 0 && cda * cdb == 0) {
        return isOverlab(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1, b.x2, b.y2);
    }
    else if (abc * abd <= 0 && cda * cdb <= 0) {
        return true;
    }
    return false;
}

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int node, int &size) {
    visited[node] = true;
    size++;
    for (int next : graph[node]) {
        if (!visited[next]) {
            DFS(next, size);
        }
    }
}

int main() {
    int N;
    cin >> N;

    graph.resize(N);
    visited.resize(N, false);
    vector<Line> lines(N);

    for (int i = 0; i < N; ++i) {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (isCross(lines[i], lines[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int numGroups = 0;
    int maxSize = 0;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            int size = 0;
            DFS(i, size);
            numGroups++;
            maxSize = max(maxSize, size);
        }
    }

    cout << numGroups << endl;
    cout << maxSize << endl;

    return 0;
}
