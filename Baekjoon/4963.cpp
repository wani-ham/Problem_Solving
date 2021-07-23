#include <iostream>
#include <string.h>
#include <utility> // pair
#include <vector>

using namespace std;

void io_init();
void dir_init();
void map_init();
void create_map();
void dfs(int x, int y);

bool map[51][51];
bool visited[51][51];
vector<pair<int, int>> dir;
int w, h;

int main() {
  int cnt = 0;
  io_init();
  dir_init();

  while(1) {
    map_init();
    cnt = 0;
    cin >> w >> h;
    if(w == 0 && h == 0) break;
    create_map();
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(map[i][j] && !visited[i][j]) {
          dfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}

void io_init() { // initialize input and output
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  return;
}

void dir_init() { // initialize direction vector
  dir.push_back(pair<int, int>(1, 0)); // down
  dir.push_back(pair<int, int>(-1, 0)); // up
  dir.push_back(pair<int, int>(0, 1)); // right
  dir.push_back(pair<int, int>(0, -1)); // left
  dir.push_back(pair<int, int>(1, 1)); // down & right
  dir.push_back(pair<int, int>(1, -1)); // down & left
  dir.push_back(pair<int, int>(-1, 1)); // up & right
  dir.push_back(pair<int, int>(-1, -1)); // up & left
  return;
}

void map_init() { // initialize array (map and visited)
  memset(map, 0, sizeof(map));
  memset(visited, 0, sizeof(visited));
  return;
}

void create_map() {
  int tmp;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> tmp;
      map[i][j] = tmp;
    }
  }
  return;
}

void dfs(int x, int y) {
  visited[x][y] = true;
  for(int i = 0; i < 8; i++) {
    int nx = x + dir[i].first;
    int ny = y + dir[i].second;
    bool check_size = (0 <= nx) && (0 <= ny) && (nx < 50) && (ny < 50); // true if x, y is in the map
    if(check_size && map[nx][ny] && !visited[nx][ny]) dfs(nx, ny);
  }
  return;
}
