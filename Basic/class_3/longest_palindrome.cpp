#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

  string line = "";
  ifstream f("input.txt");

  while (getline(f, line)) {
    cout << line << endl;
  }

}