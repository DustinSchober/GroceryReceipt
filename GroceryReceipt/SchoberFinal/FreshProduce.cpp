#include "FreshProduce.h"
#include <sstream>

FreshProduce::FreshProduce(string name_ = "Produce", double price = 0, double pounds=0, double discount=0) :Item(name_, price, discount) {
	this->pounds = pounds;
	calcPrice();
}


void FreshProduce::calcPrice() {
	ostringstream ss1, ss2;
	ss1 << pounds;
	ss2 << getPrice();
	setPriceMath(" " + ss1.str() + " NET @ $" + ss2.str() + "/lb");
	setPrice(pounds* getPrice());
}

double FreshProduce::getPounds() {
	return pounds;
}

void FreshProduce::setPounds(double pounds) {
	this->pounds = pounds;
}
