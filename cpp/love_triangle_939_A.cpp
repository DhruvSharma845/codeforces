#include <iostream>

using namespace std;

class TriangleFinder {

	private:
		int numOfVertices;
		int* neighbors;
	
	protected:
		bool hasCycleOfLengthK(int k, int source, int start);

	public:
		TriangleFinder(int _nv, int* _neighbors) {
			this->numOfVertices = _nv;
			this->neighbors = _neighbors;
		}

		bool isTrianglePresent();
		
};

bool TriangleFinder::isTrianglePresent() {
	for(int i = 1; i <= this->numOfVertices; i++) {
		if(this->hasCycleOfLengthK(3, i, i) == true) {
			return true;
		}
	}
	return false;
}

bool TriangleFinder::hasCycleOfLengthK(int k, int source, int start) {
	if( k == 0 && source == start) {
		return true;
	}
	if(k == 0) {
		return false;
	}
	return this->hasCycleOfLengthK(k - 1, this->neighbors[source], start);
}

/*int main(void) {

	int numOfVertices;
	cin>>numOfVertices;

	int* neighbors = new int[numOfVertices + 1];
	for(int i = 1; i <= numOfVertices; i++) {
		cin>>neighbors[i];
	}

	TriangleFinder* tf = new TriangleFinder(numOfVertices, neighbors);
	if(tf->isTrianglePresent() == true) {
		cout<<"YES";
	}
	else {
		cout<<"NO";
	}
	return 0;
}*/
