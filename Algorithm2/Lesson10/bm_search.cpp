#include <iostream>
#include <string>

using namespace std;

int brute_force(string haystack, string needle);
int bm_search(string haystack, string needle);


int main() {

  string haystack = "abcxbbbbcccbbc";
  string needle = "cbbc"; 
	
  int pos,i ;
	
  pos = bm_search(haystack, needle);
	

  if (pos >= 0) {  
    cout << "pos = " <<  pos << endl;		
    for(i = pos - 5; i < pos + (int)needle.size() + 5; i++){
      if(i >= 0 && i < (int)haystack.size()){
	cout <<  haystack.at(i);
      }
    }
    cout << endl; 
  }  

  else { 
    cout <<"Not found."<< endl; 
  } 
  return 0; 
}  

int brute_force(string haystack, string needle){
  for(int h = 0; h < (int)haystack.size() - (int)needle.size() + 1; h++)
    for(int n = 0; haystack.at(h + n + 1) == needle.at(n + 1) && n < needle.size(); n++)
      if( n + 2 == (int)needle.size() ) // (int)needle.size() == 4
	return h;
  
  return -1;
}

int bm_search(string haystack, string needle) 
{
  int table[128];
  for(int i = 0; i < 128; i++)
    table[i] = (int)needle.size();
  for(int i = 0; i < needle.size() - 1; i++)
    table[(int)needle.at(i)] = needle.size() - i - 1;

  int i = (int)needle.size() - 1;
  while( i < (int)haystack.size()){
    int p = 0;
    for( ; haystack.at(i - p) == needle.at((int)needle.size() - p - 1); p++)
      if(p == (int)needle.size() - 1)
	return i - p;

    if(table[(int)haystack.at(i - p)] > p)
      i = i - p + table[(int)haystack.at(i - p)];
    else
      i++;
  }
  return -1;
} 
