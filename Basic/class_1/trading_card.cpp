#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ifstream f ("input.txt");
  int n,b;
  f >> n >> b;
  vector<int> cards;
  for (int i=0; i<n; ++i) {
    int ci;
    f >> ci;
    cards.push_back(ci);
  }

  sort(cards.begin(), cards.end());
  int start,end;
  if (b>n) {
    start = 0;
    end = n;
  }
  else {
    start = n-b;
    end = n;
  }
  int res = 0;
  for (int i=start; i<end; ++i) {
    cout << cards[i] << " " << i << endl;
    res += cards[i];
  }
  cout << res << endl;
}