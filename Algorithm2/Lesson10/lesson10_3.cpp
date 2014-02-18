#include <iostream>
#include <string>

using namespace std;

void brute_force(string haystack, string needle);

int main() {

  string haystack = "super long long string";
  string needle = "long"; 
	
  brute_force(haystack, needle);

  return 0; 
}  

void brute_force(string haystack, string needle){
  for(int h = 0; h < (int)haystack.size() - (int)needle.size() + 1; h++)
    for(int n = 0; n < needle.size() - 1 && haystack.at(h + n + 1) == needle.at(n + 1); n++)
      if( n + 2 == (int)needle.size() )
	cout << h <<" ";

  cout << endl;
}
