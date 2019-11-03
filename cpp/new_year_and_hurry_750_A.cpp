#include <iostream>
using namespace std;

class ProblemSolver {
	private:
		static int const totalTime = 240;
	public:
		static int maxProblemsThatCanBeSolved(int numOfProblems, int timeToReachParty);
};


int ProblemSolver::maxProblemsThatCanBeSolved(int numOfProblems, int timeToReachParty) {
	int timeRemaining = totalTime - timeToReachParty;
	if(timeRemaining >= 0) {
		int i = 1;
		int count = 0;
		while(count <= numOfProblems && timeRemaining >= 0) {
			count++;
			timeRemaining -= (5 * i);
			i++;
		}
		return (count - 1);
	}
	return 0;
} 

/*int main(void) {
	int numOfProblems, timeToParty;
	cin>>numOfProblems>>timeToParty;

	cout<<ProblemSolver::maxProblemsThatCanBeSolved(numOfProblems, timeToParty);
	
	return 0;
}*/
