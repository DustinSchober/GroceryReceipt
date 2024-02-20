#include "Item.h"
#ifndef FRESHPRODUCE_H
#define FRESHPRODUCE_H
class FreshProduce : public Item
{
private:
	double pounds;

public:
	FreshProduce(string, double, double, double);

	void calcPrice();
	double getPounds();
	void setPounds(double);
};
#endif

