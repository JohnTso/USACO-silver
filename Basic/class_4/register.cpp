#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main () {
  ifstream f ("input.txt");
  int n; f >> n;
  vector<int> registers[n];
  queue <int> q;

  char c; int num;
  while (!f.eof()) {
    f >> c >> num;
    if (c == 'C') q.push(num);
    else {
      if (q.front() == 0) break;
      registers[num-1].push_back(q.front());
      q.pop();
    }
  }

  for (int i=0; i<n; ++i) {
    cout << registers[i].size() << " ";
    for (int j=0; j<registers[i].size(); ++j) {
      cout << registers[i][j] << " ";
    }
    cout << endl;
  }
}