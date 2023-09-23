#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ifstream inp ("input.txt");
  float f,m; int n;
  inp >> f >> m >> n;
  vector<pair<long double,int> > a;
  vector<pair<long double, pair<float,float> > > ref;
  for (int i = 0; i < n; i++) {
    float fi, mi;
    inp >> fi >> mi;
    a.push_back(make_pair(fi/mi, i+1));
    ref.push_back(make_pair(fi/mi, make_pair(fi, mi)));
  }

  sort(a.rbegin(), a.rend());
  sort(ref.rbegin(), ref.rend());

  int i=0;
  vector<int> res;
  while ((f/m) < a[i].first) {
    // cout << i+1 << " "<< a[i].first << " => " << ref[i].second.first << "," << ref[i].second.second << endl;
    res.push_back(a[i].second);
    f += ref[i].second.first; m += ref[i].second.second; i++;
  }

  sort(res.begin(), res.end());

  for (int i=0; i<res.size(); ++i) cout << res[i] << endl;
  if (res.size() == 0) cout << "NONE";
}