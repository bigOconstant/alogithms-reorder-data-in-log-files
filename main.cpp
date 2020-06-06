#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>
using namespace std;

bool compareAlpha(string a, string b){
  istringstream ssa(a);
  istringstream ssb(b);

  string ida,idb;
  ssa >> ida;
  ssb >> idb;

  string secondhalfa = a.substr(ida.length(),a.length());
  string secondhalfb = b.substr(idb.length(),b.length());

  if(secondhalfa == secondhalfb){
    return (ida < idb);
      }else{
    return (secondhalfa < secondhalfb);
  }
			      
}

vector<string> reorderLogFiles(vector<string> & logs){
  vector<string> nums;
  vector<string> alpha;


  for(auto row:logs){
    istringstream ss(row);
    string ident;
    ss >>  ident;
    ss >> ident;
    if(isdigit(ident.c_str()[0])){
	nums.push_back(row);
      }
    else{
      alpha.push_back(row);
    }

  }
  
  std::sort(alpha.begin(),alpha.end(),compareAlpha);
  alpha.insert(alpha.end(),nums.begin(), nums.end());
  
  return alpha;
}


int main(){

  vector<string> test1 = {"dig1 8 1 5 1",
			  "let1 art can",
			  "dig2 3 6",
			  "cat3 1 7 1 5 1",
			  "let2 own kit dig",
			  "let3 art zero"};

  vector<string> output = {"let1 art can",
			  "let3 art zero",
			  "let2 own kit dig",
			  "dig1 8 1 5 1",
			  "dig2 3 6",
			  "cat3 1 7 1 5 1" };

  assert(reorderLogFiles(test1) == output);
  cout<<"Test passed"<<endl;
  
  return 0;
}
