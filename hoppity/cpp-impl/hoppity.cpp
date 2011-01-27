/*
 * =====================================================================================
 *
 *       Filename:  hoppity.cpp
 *
 *    Description:  Hoppity
 *
 *        Version:  1.0
 *        Created:  01/26/2011 02:58:07 PM
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
#include<cstdlib>
using namespace std;
int main(int argc, char* argv[]){
  ifstream data_file(argv[1]);
  int num;
  data_file >>num;
  for (int i =1; i <= num; i++){
    if ((i%3==0) && (i%5==0))
      cout << "Hop"<<endl;
    else if (i%3 ==0)
      cout << "Hoppity"<<endl;
    else if (i%5 == 0)
      cout << "Hophop"<<endl;
  }
}
