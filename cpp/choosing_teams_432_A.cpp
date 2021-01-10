#include <iostream>
#include <iterator>
#include <vector>

int main() {
	int N, K;

	std::cin>>N>>K;

	std::vector<int> participations;
	participations.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		auto x = 0;
		std::cin>>x;
		participations.push_back(x);
	}

	int cluster{0};
	int finalCount{0};
	for(auto ele: participations) {
		if(5 - ele >= K) {
			cluster += 1;
		}
		if(cluster == 3) {
			finalCount++;
			cluster = 0;
		}
	}
	std::cout << finalCount <<std::endl;
}