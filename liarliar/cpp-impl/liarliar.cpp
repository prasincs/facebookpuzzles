/*
 * =====================================================================================
 *
 *       Filename:  liarliar.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2011 02:56:16 PM
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
#include<sstream>
#include<cstdlib>
#include<string>
#include<map>
#include<queue>
#include<list>
#include<iterator>

using namespace std;

class Graph {
	public:
		typedef map <string, list<string> > Map;
		Map am;


		Graph() {
		}

		void addVertex(string s) {
			Map::iterator iter = am.begin();
			iter = am.find(s);
			if(iter == am.end()){
				list<string> l;
				am[s]=l;
			}		
		}

		void addEdge(string s1, string s2) {
			addVertex(s1);
			addVertex(s2);
			am[s1].push_back(s2);
			am[s2].push_back(s1);
		}

		list<string> getVertex(string s) {
			Map::iterator iter = am.begin();
			list<string> l;
			iter = am.find(s);
			if(iter != am.end()){		
				return am[s];
			}
			return l;	
		}



};


int main(int argc, char* argv[]){
  if (argc == 1) return 0;
  string line;
  typedef map<string,int> Map;
  
  Map group;
  Map visited;
  queue<string> q;
  Graph *users;
  int usr_num,data;
  string user, u;
  users = new Graph();
  ifstream data_file(argv[1]);
  istream_iterator<string> iitr(data_file);
  
  if (data_file.fail()){
    cerr<< "Unable to open "<<argv[1]<<endl;
    exit(0);
  }
  istringstream i(*iitr);
  i >> usr_num;

  while (!data_file.eof()){
    ++iitr;
    user = *iitr;
    users->addVertex(user);
    ++iitr;
    istringstream i(*iitr);
    i>> data;
    while (data != 0){
      ++iitr;
      u = *iitr;
      users->addEdge(user,u);
      --data;
    }
  }
  data_file.close();
 
  /**
   * ugly breadth first search to partition the group
   * TODO move it to own function or inside Graph
   */

  q.push(user);
  
  int count = 1;
  while (!q.empty()){
    list<string> lst;
    user = q.front();
    lst = users->getVertex(q.front());
    for (list<string>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
      if (visited[*it] == 0)
      {
        if (group[user] ==1)
        {
          group[*it] = -1;
        }
        else 
        {
          group[*it] = 1;
          ++count;
        }
        q.push(*it);
      }
    }
    visited[q.front()] = -1;
    q.pop();
  }
  if ( usr_num -count < count ){
    cout << count << " "<< usr_num - count << endl;
  }else {
    cout << usr_num - count << " " << count << endl;
  }
}



