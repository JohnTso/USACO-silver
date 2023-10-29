#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main () {

  int n, k;
  cin >> n >> k;
  if (n == k) {
    cout << 0 << endl;
    return 0;
  } else if (n > k) {
    cout << n-k << endl;
    return 0;
  }
  
  set<int> visited; visited.insert(n);
  queue<int> prev;
  prev.push(n);
  int mins = 0;
  bool loop = true;

  while (loop) {
    int prev_len = prev.size();
    queue<int> curr;
    for (int i=0; i<prev_len; ++i) {
      int front = prev.front(); prev.pop();
      int forward=front+1, back=front-1, fly=front*2;
      if (forward == k || back == k || fly == k) {
        loop = false; break;
      }

      int v_len = visited.size();
      visited.insert(forward);
      if (forward > 0 && forward <= 10000 && visited.size() == v_len+1) curr.push(forward);

      v_len = visited.size();
      visited.insert(back);
      if (back > 0 && back <= 10000 && visited.size() == v_len+1) curr.push(back); 

      v_len = visited.size();
      visited.insert(fly);
      if (fly > 0 && fly <= 10000 && visited.size() == v_len+1) curr.push(fly); 

    }
    prev = curr; 
    mins++;
  }
  cout << mins << endl;
}