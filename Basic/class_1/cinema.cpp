#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int binary_search(int t, vector<int> v) {
  int i=0,j=v.size()-1;
  while (j-i > 1) {
    int mid_ind = (j+i)/2;
    if (v[mid_ind] >= t) j = mid_ind;
    else if (v[mid_ind] < t) i = mid_ind;
  }
  if (t < v[i]){
    if (i>0) return i-1;
    return i;
  } else if (v[i] <= t && t < v[j]) {
    return j;
  } else { // (t >= t[j])
    return j+1;
  }
}

int main () {
  int col, row;

  ifstream f ("input.txt");
  f >> col >> row;
  vector<int> sort_dis, dis;
  sort_dis.push_back(0); // this means nothing but to prevent seg fault
  int bestx = (col-1)/2, besty = 0;
  for (int r=0; r<row; r++) {
    for (int c=0; c<col; c++) {
      int d = pow((r-besty),2) + pow((c-bestx),2);
      // int ind = binary_search(d,sort_dis);
      // sort_dis.insert(sort_dis.begin() + ind, d);
      sort_dis.push_back(d);
      dis.push_back(d);
      // the zero means nothing here, but this can make it do binary search on all vectors
    }
  }
  sort(sort_dis.begin(),sort_dis.end());
  sort_dis.erase(sort_dis.begin());
  // since theres an extra pair added to prevent seg fault, simply remove it at end


  int count[500000] = {};
  vector<vector<int > > res;
  vector<int> row_p;
  for (int i=0; i<dis.size(); ++i) {
    int ind = binary_search(dis[i], sort_dis);
    row_p.push_back(ind+count[dis[i]]);
    // cout << ind+count[dis[i]] << " ";
    if ((i+1)%col == 0) {
      res.push_back(row_p);
      row_p.clear();
    };
    count[dis[i]]++;
  }
  for (int i=0; i<res.size(); ++i) {
    for (int j=0; j<col; ++j) {
      cout << res[res.size()-i-1][j] << " ";
    }
    cout << endl;
  }
  
  
  
}