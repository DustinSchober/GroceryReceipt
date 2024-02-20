#include "MeasuredProduct.h"
#include <sstream>

MeasuredProduct::MeasuredProduct(string name_ = "Test", double price = 0, int quantity=0, double discount=0) :Item(name_, price, discount) {
	this->quantity = quantity;
	calcPrice();
}

void MeasuredProduct::calcPrice() {
	ostringstream ss1, ss2;
	ss1 << quantity;
	ss2 << getPrice();
	setPriceMath(" " + ss1.str() + " NET @ $" + ss2.str() + "/ea");
	setPrice(quantity * getPrice());
}

int MeasuredProduct::getQuantity() {
	return quantity;
}

void MeasuredProduct::setQuantity(int quantity) {
	this->quantity = quantity;
}
