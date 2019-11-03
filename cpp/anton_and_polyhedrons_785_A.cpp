#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Polyhedrons {

	private:
		unordered_map<string, int> polyhedrons_faces;

	public:
		Polyhedrons() {
			this->polyhedrons_faces["Tetrahedron"] = 4;
			this->polyhedrons_faces["Cube"] = 6;
			this->polyhedrons_faces["Octahedron"] = 8;
			this->polyhedrons_faces["Dodecahedron"] = 12;
			this->polyhedrons_faces["Icosahedron"] = 20;
		}
		int getNumberOfFaces(string s);
};

int Polyhedrons::getNumberOfFaces(string s) {
	if(this->polyhedrons_faces.find(s) != this->polyhedrons_faces.end()) {
		return this->polyhedrons_faces[s]; 
	}
	return 0;
}

/*int main(void) {
	int N;
	cin>>N;

	Polyhedrons* ph = new Polyhedrons();
	int sum = 0;
	for(int i = 0; i < N; i++) {
		string s;
		cin>>s;
		sum += ph->getNumberOfFaces(s);			
	}
	cout<<sum;
	return 0;	
}*/
