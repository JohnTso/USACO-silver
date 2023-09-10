#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int>& v, int target, bool lb) {
  int i=0, j=v.size()-1;
  int mid_ind;
  while (j-i > 1) {
    mid_ind = (j+i)/2;
    if (v[mid_ind] >= target) j = mid_ind;
    else if (v[mid_ind] < target) i = mid_ind;
  }

  if ((target == v[i] && lb) || target < v[i]) return i;
  else if ((target == v[j] && !lb) || target > v[j]) return j+1;
  else if (v[i] < target < v[j]) return j;
  return -1;
}

int main () {
  ifstream f ("input.txt");
  int n, q;
  f >> n >> q;
  vector<int> pos;
  for (int i=0; i<n; ++i) {
    int p; f >> p;
    pos.push_back(p);
  }
  sort(pos.begin(), pos.end());

  for (int k=0; k<q; ++k) {
    int lower,upper; f >> lower >> upper;
    int lb, ub;
    // lower bound
    // int i=0, j=pos.size()-1;
    // int mid_ind;
    // while (j-i > 1) {
    //   mid_ind = (j+i)/2;
    //   if (pos[mid_ind] >= lower) j = mid_ind;
    //   else if (pos[mid_ind] < lower) i = mid_ind;
    // }
    // if ((lower == pos[i] && true) || lower < pos[i]) lb = i;
    // else if ((lower == pos[j] && false) || lower > pos[j]) lb = j+1;
    // else if (pos[i] < lower < pos[j]) lb = j;

    // // upper bound 
    // i=0, j=pos.size()-1;
    // while (j-i > 1) {
    //   mid_ind = (j+i)/2;
    //   if (pos[mid_ind] >= upper) j = mid_ind;
    //   else if (pos[mid_ind] < upper) i = mid_ind;
    // }
    // if ((upper == pos[i] && false) || upper < pos[i]) ub = i;
    // else if ((upper == pos[j] && true) || upper > pos[j]) ub = j+1;
    // else if (pos[i] < upper < pos[j]) ub = j;

    int lb=binary_search(pos, lower, true), ub = binary_search(pos, upper, false);
    cout << ub-lb << endl;
  }
}
// passed yay