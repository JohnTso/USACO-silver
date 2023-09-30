#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
  ifstream f ("input.txt");

  int n; f >> n;
  vector<int> line;
  int count = 1, ;
  char n,end;
  for (int i =0; i<n ; ++i) {
    f >> n >> end;
    if (n == 'A') {
      if (end == 'L') {
        line.push_front(count);
      } else {
        line.push_back(count);
      }
    } else {
      if (end == 'L') {
        line.pop_front();
      } else {
        line.pop();
      }
    }
  }
}