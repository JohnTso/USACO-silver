#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<double>& v, int target, bool upper_b) {
  int i=0, j=v.size()-1;
  int mid, mid_ind;
  while (j-i > 1) {
    mid_ind = (i+j)/2;
    mid = v[mid_ind];
    if (mid < target) i = mid_ind;
    else if (mid > target) j = mid_ind;
    else return mid_ind;
  }
  if (upper_b) {
    if (v[j] <= target) return j;
    return i;
  } else {
    if (v[i] >= target) return i;
    return j;
  }

}

int main() {
  ifstream f ("input.txt");
  int n; f >> n;
  vector<double> cows;
  for (int i=0; i<n; ++i) {
    double pos; f >> pos;
    cows.push_back(pos);
  }
  sort(cows.begin(), cows.end());

  unsigned total = 0;
  for (int i=0; i<n-2; ++i) {
    for (int j=i+1; j<n; ++j) {
      int dis = cows[j]-cows[i];
      int min = cows[j]+dis, max = cows[j]+dis+dis;
      if (min > cows[n-1]) break;
      int lower_bound = binary_search(cows, min, false), upper_bound = binary_search(cows, max, true);
      total += upper_bound - lower_bound + 1;
    }
  }
  cout << fixed << setprecision(0) << total << endl;
}
