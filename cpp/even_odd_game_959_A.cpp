#include <iostream>
#include <string>

using namespace std;

class EvenOddGame {
	public:
		string determineWinner(long int num);		
	 
};

string EvenOddGame::determineWinner(long int num) {
	if(num % 2 == 0 ) {
		return "Mahmoud";
	}
	else {
		return "Ehab";
	} 
}

/*int main(void) {
	long int num;
	cin>>num;

	EvenOddGame* g = new EvenOddGame();
	cout<<g->determineWinner(num);
	
	return 0;
}*/
