/*
 * =====================================================================================
 *
 *       Filename:  breathalyzer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2011 09:04:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prasanna Gautam (mn), prasanna.gautam@trincoll.edu
 *        Company:  Trinity College
 *
 * =====================================================================================
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
#include<map>
using namespace std;

/*
 * Levenshtein Distance
 * Courtesy wikipedia
 */
unsigned int edit_distance (const string s1, const string s2){
  const size_t m = s1.length(), n = s2.length();
  //cout << m << " "<< n << endl;
  unsigned int d[m+1][n+1];
  //clear everything
  for (unsigned int row=0; row< m+1; row++){
    for (unsigned int col=0; col< n+1; col++){
      d[row][col] = 0;
    }
  }
  //cout << "Here"<<endl;
  for (unsigned int i = 1; i <= m; ++i) d[i][0] = i;
  for (unsigned int i = 1; i <= n; ++i) d[0][i] = i;

  for (unsigned int i = 1; i <= m; ++i){
    for (unsigned int j = 1; j <= n; ++j){
      // cout << s1[i-1] <<" "<< s2 [j-1]<<endl;
      d[i][j] = min(min (d[i-1][j] + 1,  //deletion
                         d[i][j-1] +1), //insertion
                    d[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0:1) // substitution
                   );
      //cout << d[i][j]<<" ";

    }
  }

  return d[m][n];
}

/**
 * Function to strip whitespace
 */
void strip_str(std::string& input_str)
{
  if(input_str.empty()) return;
  int startIndex = input_str.find_first_not_of(" ");
  int endIndex = input_str.find_last_not_of("\r\n");
  std::string temp_str = input_str;
  input_str.erase();
  input_str = temp_str.substr(startIndex, (endIndex-startIndex+ 1) );
}


int minEdit(string s, vector<string>& dict){
  int min= 9999999;
  int cur = 0;
  for (vector<string>::iterator iter = dict.begin(); iter != dict.end(); iter++){
    cur = edit_distance(s, *iter);
    if (cur < min) min = cur;
  }
  return min;
}

int main(int argc, char* argv[]){
  if (argc ==1){
    cerr << "Need a filename"<<endl;
    exit(0);
  }
  map<int, vector<string> > dict_map;
  int max_len = 25;
  string sentence;
  ifstream input_file(argv[1]);
  getline(input_file, sentence);
  //cout << sentence;
  input_file.close();
  string DICT="/var/tmp/twl06.txt";
  ifstream dict_file(DICT.c_str());
  istream_iterator<string> iitr (dict_file);
  while (!dict_file.eof()){
    string word=*iitr++;
    //convert to lowercase
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    //cout << word <<endl;
    dict_map[word.size()-1].push_back(word);
    //dict.push_back(word);
  }

  dict_file.close();

  string buf;
  stringstream ss(sentence);
  vector<string> words;
  while(ss>>buf)
    words.push_back(buf);

  string min_str;
  vector<string>::iterator iter;
  int sum= 0,min,cur;
  for (iter= words.begin(); iter != words.end(); iter++){
    min= 9999999;
    cur = 0;
    int len_str = (*iter).size();
    int start_range = len_str - 4;
    int end_range = len_str +4;
    //cout << start_range << " " << end_range<<endl;
    if (start_range < 0) start_range =0; 
    if (end_range > 25) end_range =25;
    //start_range =0; end_range = 25;
    for (int k = start_range; k < end_range; k++){
      vector<string> d = dict_map[k];
      for (vector<string>::iterator iter2 = d.begin(); iter2 != d.end(); iter2++){
        cur = edit_distance(*iter, *iter2);
        if (cur < min){
          min = cur;
          min_str = *iter2;
        }
      }
    }
#if DEBUG
    cout << *iter << "=>" << min_str << "("<<min<<")"<<endl;
#endif
    sum += min;
  }
  cout << sum<<endl;
  //cout<< edit_distance("kitten", "sitting")<<endl;
}
