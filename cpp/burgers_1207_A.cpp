#include <iostream>

using namespace std;

class BurgerProfitCalculator {
	private:
		int buns;
		int patties;
		int cutlets;
		
		int hbPrice;
		int cbPrice;
	public:
		BurgerProfitCalculator(int buns, int patties, int cutlets, int hbPrice, int cbPrice) {
			this->buns = buns;
			this->patties = patties;
			this->cutlets = cutlets;
			this->hbPrice = hbPrice;
			this->cbPrice = cbPrice;		
		}
		int calculateProfit();
};

int BurgerProfitCalculator::calculateProfit() {
	//int firstP, secondP;
	int profit = 0;
	if(this->hbPrice > this->cbPrice) {
		if(2 * this->patties <= this->buns) {
			profit += this->patties * this->hbPrice;
 			this->buns -= 2 * this->patties; 
		}
		else {
			profit += (this->buns/2) * this->hbPrice;
			this->buns = 0;	
		}
		if(2 * this->cutlets <= this->buns) {
			profit += this->cutlets * this->cbPrice;
 			this->buns -= 2 * this->cutlets; 
		}
		else {
			profit += (this->buns/2) * this->cbPrice;
			this->buns = 0;;
		}
	}
	else {
		if(2 * this->cutlets <= this->buns) {
			profit += this->cutlets * this->cbPrice;
 			this->buns -= 2 * this->cutlets; 
		}
		else {
			profit += (this->buns/2) * this->cbPrice;
			this->buns = 0;;
		}
		if(2 * this->patties <= this->buns) {
			profit += this->patties * this->hbPrice;
 			this->buns -= 2 * this->patties; 
		}
		else {
			profit += (this->buns/2) * this->hbPrice;
			this->buns = 0;	
		}
	}
	return profit;	
}


int main(void) {
	int queries;
	cin>>queries;

	for(int i = 0; i < queries; i++) {

		int buns, patties, cutlets;
		cin>>buns>>patties>>cutlets;
		int hamburger, chickenburger;
		cin>>hamburger>>chickenburger;
	
		BurgerProfitCalculator* bpc = new BurgerProfitCalculator(buns, patties, cutlets, hamburger, chickenburger);
		cout<<bpc->calculateProfit()<<endl;
	}
}
