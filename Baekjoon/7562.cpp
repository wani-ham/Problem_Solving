#include <iostream>
#include <string.h> // memset
#include <utility> // pair
#include <vector>
#include <queue>

using namespace std;

void io_init();
void dir_init();
void visited_init();
void bfs(int x, int y);

bool visited[301][301];
vector<pair<int, int>> dir;
int n, l;
pair<int, int> cur, des; // current position, destination

int main() {
  io_init();
  dir_init();

  cin >> n;
  for(int i = 0; i < n; i++) {
    visited_init();
    cin >> l;
    cin >> cur.first >> cur.second;
    cin >> des.first >> des.second;
    bfs(cur.first, cur.second);
  }
  return 0;
}

void io_init() { // initialize input and output
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return;
}

void dir_init() { // initialize direction vector
  dir.push_back(pair<int, int>(2, 1)); 
  dir.push_back(pair<int, int>(2, -1)); 
  dir.push_back(pair<int, int>(-2, 1)); 
  dir.push_back(pair<int, int>(-2, -1)); 
  dir.push_back(pair<int, int>(1, 2)); 
  dir.push_back(pair<int, int>(-1, 2)); 
  dir.push_back(pair<int, int>(1, -2)); 
  dir.push_back(pair<int, int>(-1, -2)); 
  return;
}

void visited_init() { // initialize array (visited)
  memset(visited, 0, sizeof(visited));
  return;
}

void bfs(int ix, int iy) { // initial x, y
  queue<pair<int, int>> q;
  q.push(pair<int, int>(ix, iy));
  queue<int> qcnt; // queue cnt
  qcnt.push(0);
  visited[ix][iy] = true;
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    int cnt = qcnt.front();
    q.pop();
    qcnt.pop();
    if(x == des.first && y == des.second) { // if knight reaches destination pos
      cout << cnt << "\n";
      return;
    }

    for(int i = 0; i < 8; i++) {
      int nx = x + dir[i].first;
      int ny = y + dir[i].second;
      bool check_pos = (0 <= nx) && (0 <= ny) && (nx < l) && (ny < l);
      if(check_pos && !visited[nx][ny]) {
        visited[nx][ny] = true;
        q.push(pair<int, int>(nx, ny));
        qcnt.push(cnt + 1);
      }
    }
  }
  cout << 0 << "\n"; // if knight cannot reach the destination position
  return;
}
