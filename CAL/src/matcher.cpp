#include "Matcher.h"

void compute_prefix(string pattern, vector<int> & prefix) {
    int m = pattern.length();
    prefix[0] = 0;
    int k = 0;
    for (int q = 2; q < m; q++) {
        while (k > 0 && pattern[k + 1] != pattern[q])
            k = prefix[k];
        if (pattern[k + 1] == pattern[q])
            k = k + 1;
        prefix[q] = k;
    }
}

int kmp(string text, string pattern) {
    int numCharMatched = 0;
    int n = text.length();
    int m = pattern.length();
    vector<int> prefix(m);
    compute_prefix(pattern, prefix);

    int q = 0;
    for (int i = 1; i < n; i++) {
        while (q > 0 && pattern[q + 1] != text[i])
            q = prefix[q];
        if (pattern[q + 1] == text[i]) {
            q++;
        }
        if (q == m - 1) {
        	numCharMatched++;
            q = prefix[q];
        }
    }

    return numCharMatched;
}
int pesquisaExata(string toSearch) {
	ifstream streamRoads;
	streamRoads.open("estradas.txt");
	string line;
	int id;
	string rua;
	string ignoreString;
	char ignoreChar;

	int idFound = 0;
	int matchingChars = 0;
	int final = 0;

	while (!streamRoads.eof()){
		getline(streamRoads, line);
		stringstream ssFicheiro(line);
		ssFicheiro >> id;
		ssFicheiro >> ignoreChar;
		getline(ssFicheiro,rua,';');
		ssFicheiro >> ignoreChar;
		ssFicheiro >> ignoreString;

		matchingChars = kmp(toSearch, rua);
		if(matchingChars > final){
			final = matchingChars;
			idFound = id;
		 }

	}

	if(idFound == 0)
    	cout << endl << toSearch << " sem correspondencia" << endl;

    streamRoads.close();
    return idFound;

}

int editDistance(string pattern, string text) {
    int n = text.length();
    vector<int> d(n + 1);
    int old, newChar;
    for (int j = 0; j <= n; j++)
        d[j] = j;
    int m = pattern.length();
    for (int i = 1; i <= m; i++) {
        old = d[0];
        d[0] = i;
        for (int j = 1; j <= n; j++) {
            if (pattern[i - 1] == text[j - 1])
            	newChar = old;
            else {
            	newChar = min(old, d[j]);
            	newChar = min(newChar, d[j - 1]);
            	newChar = newChar + 1;
            }
            old = d[j];
            d[j] = newChar;
        }
    }
    return d[n];
}

vector<string> pesquisaAproximada(string toSearch, int diffRange) {

	toSearch = to_uppercase(toSearch);

	ifstream streamRoads;
	streamRoads.open("estradas.txt");
	string line;
	string id;
	string rua;
	string ignoreString;
	char ignoreChar;

    vector<string> idsRuas;

    int numDifferences = 0;

    while (!streamRoads.eof()) {

    	numDifferences = 0;

		getline(streamRoads, line);
		stringstream ssFicheiro(line);
		getline(ssFicheiro,id,';');
		getline(ssFicheiro,rua,';');
		ssFicheiro >> ignoreChar;
		ssFicheiro >> ignoreString;

		rua = to_uppercase(rua);

        numDifferences = editDistance(toSearch, rua);

        if(numDifferences <= diffRange){
            idsRuas.push_back(id);
            idsRuas.push_back(rua);
        }

    }

    if(idsRuas.empty())
    	cout << endl << toSearch << " sem correspondencia aceitavel" << endl;

    streamRoads.close();
    return idsRuas;
}

string to_uppercase(string s) {
    for (size_t i = 0; i < s.size(); i++)
      s.at(i) = toupper(s.at(i));

    return s;
  }
