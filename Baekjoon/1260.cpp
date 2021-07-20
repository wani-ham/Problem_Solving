#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

void io_init();
void map_init();
void create_map();
void dfs(int x);
void bfs(int x);

bool map[1001][1001];
bool visited[1001];
int n, m, v;
queue<int> q;

int main() {
  io_init();
  cin >> n >> m >> v;
  map_init();
  create_map();

  //dfs
  dfs(v);
  cout << "\n";

  // bfs
  memset(visited, 0, sizeof(visited)); // initialize visited used from dfs
  bfs(v);
  return 0;
}

void io_init() { // initialize input and output
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  return;
}

void map_init() { // initialize array (map and visited)
  memset(map, 0, sizeof(map));
  memset(visited, 0, sizeof(visited));
  return;
}

void create_map() {
  int a, b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    map[a][b] = true;
    map[b][a] = true;
  }
  return;
}

void dfs(int x) {
  cout << x << " ";
  visited[x] = true;
  for(int i = 1; i <= n; i++) {
    if(map[x][i] && !visited[i]) dfs(i);
  }
}

void bfs(int x) {
  visited[x] = true;
  q.push(x);
  while(!q.empty()) {
    cout << q.front() << " ";
    for(int i = 1; i <= n; i++) {
      if(map[q.front()][i] && !visited[i]) {
        q.push(i);
        visited[i] = true;
      }
    }
    q.pop();
  }
  return;
}
