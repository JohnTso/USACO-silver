#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ifstream f ("input.txt");
  int n, t; f >> n >> t;
  vector<int> order;
  for (int i=0; i < n ; ++i) {
    int inp; f >> inp;
    order.push_back(inp);
  }

  sort(order.begin(), order.end());

  int i=0, j=order.size()-1;
  int count=0;
  while (i < j) {
    if (order[i]+order[j] <= t){
      count += j-i;
      i++;
    } else {
      j--;
    }
  }

  cout << count << endl;

} 