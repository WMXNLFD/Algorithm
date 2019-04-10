/*************************************************
*Author: WMXNLFD
*Date: 2019-3-25 19:34:33
*Description:不相交集类生成迷宫算法
**************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define N 10

using namespace std;

int wall_row[N+1][N];
int wall_col[N][N+1];

class DisjSets
{
public:
  explicit DisjSets(int numElements);

  int find(int x) const;
  void unionSets(int node1, int node2);
  bool connected(int node1, int node2) const
  {
    return find(node1) == find(node2);
  }

private:
  vector<int> s;
};

DisjSets::DisjSets(int numElements):s(numElements)
{
  for (int i = 0; i < s.size(); i++)
    s[i] = -1;
}

int DisjSets::find(int x) const
{
  if (s[x] < 0)
    return x;
  else
    return find(s[x]);
}

void DisjSets::unionSets(int node1, int node2)
{
  int root1 = find(node1);
  int root2= find(node2);
  if (root1==root2)
    return;
  if (s[root2] < s[root1])
    s[root1] = root2;
  else {
    if (s[root1] == s[root2])
      s[root1]--;
    s[root2] = root1;
  }
}

void fill(int value)
{
  for (int i = 0; i < N+1; i++)
    for (int j = 0; j < N; j++)
      wall_row[i][j] = value;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N+1; j++)
      wall_col[i][j] = value;
}

void print()
{
  int i, j;

  for (i = 0; i < N+1; i++) {
    for (j = 0; j < N+1; j++) {
      if (i > 0)
    if (wall_col[i-1][j])
      cout << "|";
    else
      cout << " ";
      if (j < N)
    if (i > 0)
      if (wall_row[i][j])
        cout << "_";
      else
        cout << " ";
    else
      if (wall_row[i][j])
        cout << " _";
      else
        cout << "  ";
    }
    cout << endl;
  }
}

void map_rand(int x, int &type, int &a, int &b)
{
  type = 0;
  if (x >= N*(N-1)) type = 1;
  if (type == 0) {
    a = x / (N - 1);
    b = x % (N - 1) + 1;
  } else {
    x -= N*(N-1);
    a = x / N + 1;
    b = x % N;
  }
}

void map_pos(int type, int a, int b, int &node1, int &node2)
{
  if (type == 0) {
    node1 = a * N + b - 1;
    node2 = a * N + b;
  } else {
    node1 = (a - 1) * N + b;
    node2 = (a - 1) * N + b + N;
  }
}

int randselect(void)
{
  int range = N*(N-1)*2;
  return rand() % range;
}

int main()
{
  fill(1);
  srand(time(0));
  wall_row[0][0] = 0;
  wall_col[0][0] = 0;
  wall_row[N][N-1] = 0;
  wall_col[N-1][N] = 0;
  //  print();
  int amount = N * N;
  DisjSets s(amount);
  while (!s.connected(0, amount-1)) {
    int type, a, b;
    do {
      int wall = randselect();
      map_rand(wall, type, a, b);
    } while ((type == 0 && wall_col[a][b] == 0) ||
       (type == 1 && wall_row[a][b] == 0));
    int node1, node2;
    map_pos(type, a, b, node1, node2);
    if (!s.connected(node1, node2)) {
      if (type == 0)
    wall_col[a][b] = 0;
      else
    wall_row[a][b] = 0;
      s.unionSets(node1, node2);
    }
  }
  print();
  return 0;
}
