#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  vector<pair<int, pair<int, int> > > curr1;
  vector<pair<int, pair<int, int> > > curr2;

  ifstream f ("input.txt");
  int n1, n2; 
  f >> n1 >> n2;
  // cout << n1 << " " << n2;
  for (int i=0; i<n1; ++i) {
    int step; char dir;
    f >> step >> dir;
    if (dir == 'L') step *= -1;
    curr1.push_back(make_pair(step, make_pair(0,0)));
  }

  for (int i=0; i<n2; ++i) {
    int step; char dir;
    f >> step >> dir;
    if (dir == 'L') step *= -1;
    curr2.push_back(make_pair(step, make_pair(0,0)));
  }

  bool end = false; int end_pt;
  int i=0, j=0;
  while (!end) {
    int abs_step1 = abs(curr1[i].first), abs_step2 = abs(curr2[j].first);

    if (i>0) curr1[i].second.first = curr1[i-1].second.second;
    if (j>0) curr2[j].second.first = curr2[j-1].second.second;
  
    if (abs_step1 <= abs_step2) {
      curr1[i].first = 0;
      curr1[i].second.second += curr1[i].first;
      if (curr2[j].first < 0) {
        curr2[j].first = (abs_step2-abs_step1)*-1;
        curr2[j].second.second += (abs_step2-abs_step1)*-1;
      }
      else {
        curr2[j].first = (abs_step2-abs_step1);
        curr2[j].second.second += (abs_step2-abs_step1);
      }
      i++;
    } else {
      curr2[j].first = 0;
      curr2[j].second.second += curr2[j].first;
      if (curr1[i].first < 0) {
        curr1[i].first = (abs_step1-abs_step2)*-1;
        curr1[i].second.second += (abs_step1-abs_step2)*-1;
      }
      else {
        curr1[i].first = (abs_step1-abs_step2);
        curr1[i].second.second += (abs_step1-abs_step2);
      }
      j++;
    }
    if (i == curr1.size()) end = true;
    else if (j == curr2.size()) end = true;

    // cout << curr1[i].first << " " << curr1[i].second.first << ", " << curr1[i].second.second << endl;
    // cout << curr2[j].first << " " << curr2[j].second.first << ", " << curr2[j].second.second << endl;
  }
}