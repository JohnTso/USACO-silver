#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

  ifstream f ("text.txt");

  int n; f >> n;

  stack<pair<int, int> > s;
  vector<pair< int, int > > v;

  for (int i=0; i<n; ++i) {
  
    int h; f >> h;
  
    while (!s.empty() && h > s.top().second) {
      v.push_back(make_pair(i+1, s.top().first));
      s.pop();
    }
  
    s.push(make_pair(i+1,h));
  }

  sort(v.begin(), v.end());

  for (int i=1; i<=n ; ++i) {
    if (i >= v.size() || i != v[i-1].first) {
      cout << 0 << endl;
    } else {
      cout << v[i-1].first
    }
  }


}