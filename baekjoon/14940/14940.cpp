#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    int x, y;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<tuple<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // map input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    // find destination
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < m; ++j) {
            if(map[i][j] == 2) {
                x = i;
                y = j;
                dist[i][j] = 0;
                flag = true;
                break;
            }
        }
        if (flag){break;}
    }

    q.push({x, y});
    visited[x][y] = true;

    // calculate distance
    while(!q.empty()){
        x = get<0>(q.front());
        y = get<1>(q.front());
        q.pop();

        if(x > 0 && !visited[x-1][y] && map[x-1][y] != 0){
            q.push({x-1, y});
            dist[x-1][y] = dist[x][y]+1;
            visited[x-1][y] = true;
        }
        if(x < n-1 && !visited[x+1][y] && map[x+1][y] != 0){
            q.push({x+1, y});
            dist[x+1][y] = dist[x][y]+1;
            visited[x+1][y] = true;
        }
        if(y > 0 && !visited[x][y-1] && map[x][y-1] != 0){
            q.push({x, y-1});
            dist[x][y-1] = dist[x][y]+1;
            visited[x][y-1] = true;
        }
        if(y < m-1 && !visited[x][y+1] && map[x][y+1] != 0){
            q.push({x, y+1});
            dist[x][y+1] = dist[x][y]+1;
            visited[x][y+1] = true;
        }
    }

    //put zeroes
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 0){
                dist[i][j] = 0;
            }
        }
    }

    //output
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}