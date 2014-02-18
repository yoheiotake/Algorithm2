#include <iostream>
#include <string>

using namespace std;

int brute_force(string haystack, string needle);
int bm_search(string haystack, string needle);


int main() {

  string haystack = "super long long string";
  string needle = "long"; 
	
  int pos,i ;
	
  pos = brute_force(haystack, needle);

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
    for(int n = 0; n < needle.size() - 1 && haystack.at(h + n + 1) == needle.at(n + 1); n++)
      if( n + 2 == (int)needle.size() ) // (int)needle.size() == 4
	return h;
  
  return -1;
}

int bm_search(string haystack, string needle) 
{ 
  return -1;
} 
