#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item
{
private:
	static double delivery;
	static double tip;
	double price;
	string name;
	string priceMath;
	double discount;

public:
	Item();

	Item(string);
	Item(string, double, double);
	string getName();
	void setName(string);
	double getPrice();
	void setPrice(double);
	void setDiscount(double);
	double getDiscount();
	void setPriceMath(string);
	string getPriceMath();

	static double getDelivery();
	static void setDelivery(double);
	static double getTip();
	static void setTip(double);
};
#endif