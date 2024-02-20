#include "Item.h"

#ifndef MEASUREDPRODUCT_H
#define MEASUREDPRODUCT_H

class MeasuredProduct : public Item
{
private:
	int quantity;

public:
	MeasuredProduct(string, double, int, double);

	void calcPrice();
	int getQuantity();
	void setQuantity(int);
};
#endif
