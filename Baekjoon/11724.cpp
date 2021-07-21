#include <iostream>
#include <string.h>

using namespace std;

void io_init();
void map_init();
void create_map();
void dfs(int x);

bool map[1001][1001];
bool visited[1001];
int n, m;

int main() {
  int cnt = 0; // number of connected components
  io_init();
  cin >> n >> m;
  map_init();
  create_map();

  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      dfs(i);
      cnt++;
    }
  }
  cout << cnt;
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
  int u, v;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    // undirected graph
    map[u][v] = true;
    map[v][u] = true;
  }
  for(int i = 1; i <= n; i++) map[i][i] = true; // consider the dots!!
  return;
}

void dfs(int x) {
  visited[x] = true;
  for(int i = 1; i <= n; i++) {
    if(map[x][i] && !visited[i]) dfs(i);
  }
  return;
}
