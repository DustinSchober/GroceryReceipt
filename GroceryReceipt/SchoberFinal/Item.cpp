#include "Item.h"
#include<string>

Item::Item() {
	price = 0;
	discount = 0;
}

Item::Item(string name_ = "Item") :name(name_) {
	price = 0;
	discount = 0;
}

Item::Item(string name_, double price, double discount) :name(name_) {
	this->price = price;
	this->discount = discount;
}

string Item::getName() {
	return name;
}

void Item::setName(string name) {
	this->name = name;
}

double Item::getPrice() {
	return price;
}

void Item::setPrice(double price) {
	this->price = price;
}

void Item::setPriceMath(string priceMath_) {
	priceMath = priceMath_;
}

string Item::getPriceMath() {
	return priceMath;
}

double Item::getDiscount() { 
	return discount; 
}

void Item::setDiscount(double discount) {
	this->discount = discount; 
}

double Item::getDelivery() {return delivery;}
void Item::setDelivery(double delivery_) {delivery = delivery_;}
double Item::getTip() {return tip;}
void Item::setTip(double tip_) {tip = tip_;}
