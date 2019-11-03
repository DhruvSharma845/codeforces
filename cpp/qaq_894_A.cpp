#include <iostream>
#include <string>

using namespace std;

class SubsequenceFinder {
	private:
		string s;
		string pattern;
	public:
		SubsequenceFinder(string& s, string& pattern) {
			this->s = s;
			this->pattern = pattern;
		}
		int findNumOfSubsequences();
};

int SubsequenceFinder::findNumOfSubsequences() {
	int totalVal = 0;
	int** table = new int*[this->pattern.size()];
	for(int i = 0; i < this->pattern.size(); i++) {
		table[i] = new int[this->s.size()];
		totalVal = 0;
		for(int j = 0; j < this->s.size(); j++) {
			table[i][j] = 0;
			if(j >= i) {
				if(this->s[j] == this->pattern[i]) {

					if(i == 0) {
						table[i][j] = 1;
					}
					else {
						for(int m = j - 1; m >= 0; m--) {
							if(this->s[m] == this->pattern[i-1]) {
								table[i][j] += table[i-1][m];
							}
						}
					}	


				}
			}
			totalVal += table[i][j];
		}
	}
	return totalVal;
}

/*int main(void) {
	string s;
	cin>>s;

	string pattern = "QAQ";

	SubsequenceFinder* qf = new SubsequenceFinder(s, pattern);
	cout<<qf->findNumOfSubsequences(); 	
	return 0;
}*/
