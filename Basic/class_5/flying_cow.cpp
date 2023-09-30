#include <iostream>
#include <queue>
#include <set>
#include <fstream>

using namespace std;

int main () {
  ifstream f ("input.txt");
  int n; f >> n;

  if (n == 1) { // corner case
    cout << 0 << endl;
    return 0;
  }

  queue<int> prev_q; prev_q.push(1);
  set<int> visited; visited.insert(1);
  bool loop = true;
  int energy = 0;
  int prev;
  while (loop) {

    energy++;
    queue<int> curr_q;
    while(!prev_q.empty()) {
      int front = prev_q.front(); prev_q.pop();
      int a=front-1, b=front+1, c=front*3;
      // checking a
      if (a == n) {
        loop = false;
        break;
      }
      prev = visited.size();
      visited.insert(a);
      if (a > 0 && visited.size() == prev+1) curr_q.push(a);
      // checking b
      if (b == n) {
        loop = false;
        break;
      }
      prev = visited.size();
      visited.insert(b);
      if (b > 0 && visited.size() == prev+1) curr_q.push(b);
      // checking c
      if (c == n) {
        loop = false;
        break;
      }
      prev = visited.size();
      visited.insert(c);
      if (c > 0 && visited.size() == prev+1) curr_q.push(c);

    }
    prev_q = curr_q;
  }
  cout << energy << endl;

}