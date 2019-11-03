#include<iostream>

using namespace std;

class QuantityOptimizer {
	private:
		int* amounts;
		int size;
	public:
		QuantityOptimizer(int* _amounts, int _size) {
			this->amounts = _amounts;
			this->size = _size;
		}
		int findMinimumQuantityToMakeSum(long int sum);
};

int QuantityOptimizer::findMinimumQuantityToMakeSum(long int sum) {
	int amount_index = this->size - 1;
	while(this->amounts[amount_index] > sum) {
		amount_index--;	
	}
	int quantity = 0;
	while(sum > 0) {
		quantity += (sum/this->amounts[amount_index]);
		sum = sum % this->amounts[amount_index];
		amount_index--;
	}
	return quantity;
}

/*int main(void) {

	int amounts[] = {1, 5, 10, 20, 100};

	long int sum;
	cin>>sum;

	QuantityOptimizer* qo = new QuantityOptimizer(amounts, 5);
	cout<<qo->findMinimumQuantityToMakeSum(sum);
	
	return 0;
}*/
