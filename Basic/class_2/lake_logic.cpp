#include <iostream>
#include <fstream>

using namespace std;

int main () {

  ifstream f ("input.txt");

  int r,c; f >> r >> c;
  int lake[r][c];
  for (int i=0; i<r; ++i) {
    for (int j=0; j<c; ++j) {
      int depth; f >> depth;
      lake[i][j] = depth;
    }
  }
  
  int max=0;
  for (int i=0; i<r; ++i) {
    for (int j=0; j<c; ++j) {

      int depth = lake[i][j];
      bool l = (i > 0), r = (i < c-1), u = (j > 0), d = (j < r-1), repeat = false;

      if (l) {
        if (lake[i-1][j] == depth) repeat = true;
        if (u) {
          if (lake[i-1][j+1] == depth) repeat = true;
        }
        if (d) {
          if (lake[i-1][j-1] == depth) repeat = true;
        }
      }

      if (r) {
        if (lake[i+1][j] == depth) repeat = true;
        if (u) {
          if (lake[i+1][j+1] == depth) repeat = true;
        }
        if (d) {
          if (lake[i+1][j-1] == depth) repeat = true;          
        }
      }

      if (u) {
        if (lake[i][j+1] == depth) repeat = true;

      }
      if (d) {
        if (lake[i][j-1] == depth) repeat = true;
      }
      // cout << depth << " ";
      if (repeat && depth > max) max = depth;

    }
  }
  cout << max << endl;
}