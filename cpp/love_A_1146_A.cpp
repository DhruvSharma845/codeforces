#include <iostream>
#include <string>

using namespace std;

int findLengthOfLongestGoodString(string s) {
	int countOfA = 0;	
	for(char const& c: s) {
		if(c == 'a') {
			countOfA++;
		}
	}

	return (countOfA <= s.size()/2) ? ((2 * countOfA) - 1) : s.size();
}

/*int main(void) {
	string s;
	cin>>s;

	cout<<findLengthOfLongestGoodString(s);
	
	return 0;
}*/
