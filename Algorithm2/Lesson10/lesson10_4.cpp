#include <iostream>
#include <string>

using namespace std;

void bm_search(string haystack, string needle);


int main() {

  string haystack = "abcxbbbbcccbbc";
  string needle = "cbbc";
	
  bm_search(haystack, needle);

  return 0; 
}

void bm_search(string haystack, string needle) 
{
  int table[128];
  for(int i = 0; i < 128; i++)
    table[i] = (int)needle.size();
  for(int i = 0; i < needle.size() - 1; i++)
    table[(int)needle.at(i)] = needle.size() - i - 1;

  int i = (int)needle.size() - 1;
  while( i < (int)haystack.size()){
    int p = 0;
    for( ; p < (int)needle.size() && haystack.at(i - p) == needle.at((int)needle.size() - p - 1); p++)
      if(p == (int)needle.size() - 1)
	cout << i - p <<" ";

    if(table[(int)haystack.at(i - p)] > p)
      i = i - p + table[(int)haystack.at(i - p)];
    else
      i++;
  }
  cout << endl;
} 
