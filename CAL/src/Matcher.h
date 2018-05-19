#ifndef SRC_MATCHER_H_
#define SRC_MATCHER_H_

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <climits>

using namespace std;

void compute_prefix(string pattern, vector<int> & prefix);
int kmp(string text, string pattern);
int pesquisaExata(string toSearch);
int editDistance(string pattern, string text);
vector<string> numWords(string text);
vector<string> pesquisaAproximada(string toSearch, int diffRange);
string to_uppercase(string s);

#endif /* SRC_MATCHER_H_ */
