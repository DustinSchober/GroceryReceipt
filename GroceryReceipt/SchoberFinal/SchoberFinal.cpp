// Dustin Schober ITDEV-185-900 Final

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <vector>
#include <list>
#include "Item.h"
#include "FreshProduce.h"
#include "MeasuredProduct.h"

void displayCartTotal(vector<Item*>& items);
bool displayDeliveryMenu();
int displayMainMenu();
int displayFreshProduceMenu(vector<Item*>& items);
int displayMeatMenu(vector<Item*>& items);
int displayFrozenMenu(vector<Item*>& items);
double getPounds();
int getQuantity();
int getSelection();
string swapLower(string name);

ifstream infile;

double Item::tip = 0;
double Item::delivery = 0;

string boarder = "*****************************************\n";
string mainMenu[] = {"(1) Fresh Product\n","(2) Meat and Seafood\n",
						"(3) Frozen Foods\n\n","(4) Check out\n"};
string deliveryMenu[] = {"(1) Pickup\n","(2) Delivery\n\n","(5) Exit\n"};



int main() {

	vector<Item*> cart;
	double tipAmt;
	const double deliveryAmt = 20;

	int select = 0;

	bool delivery = displayDeliveryMenu();

	if (delivery) {
		Item::setDelivery(deliveryAmt);
		cout << "How much would you like to tip:";
		cin >> tipAmt;
		while (cin.fail()) {
			cout << "Invalid input please enter a number:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> tipAmt;
		}
		Item::setTip(tipAmt);
	}
	system("CLS");

	do {
		switch (displayMainMenu()) {
		case 1:
			select = displayFreshProduceMenu(cart);
			break;
		case 2:
			select = displayMeatMenu(cart);
			break;
		case 3:
			select = displayFrozenMenu(cart);
			break;
		case 4:
			displayCartTotal(cart);

		case 5:
			cout << "Application closing" << endl;
			exit(0);
		}
	} while (select != 5);

}

void displayCartTotal(vector<Item*> &items) {
	double total = 0;

	cout << fixed << setprecision(2);
	cout << "\n" << boarder;

	cout << fixed << setprecision(2);
	cout << "\n" << boarder;

	for (int i = 0; i < items.size(); i++) {
		total += items[i]->getPrice();
		cout << "   " << items[i]->getName() << endl;
		cout << setw(20) << items[i]->getPriceMath() << "\t$" << setw(7) << items[i]->getPrice() << endl;
	}
	total += Item::getTip() + Item::getDelivery();
	cout << endl;
	cout << setw(20) << "TIP" << "\t$" << setw(7) << Item::getTip() << endl;
	cout << setw(20) << "DELIVERY" << "\t$" << setw(7) << Item::getDelivery() << endl;
	cout << "\t\t\t____________\n";
	cout << setw(20) << "TOTAL" << "\t$" << setw(7) << total << endl;
	cout << endl;
	cout << "\n" << boarder;
	cout << boarder;

}

bool displayDeliveryMenu() {
	int selection = 3;
	bool delivery;

	cout << boarder;
	for (string item : deliveryMenu) { cout << item; }
	cout << boarder;

	selection = getSelection();
	switch (selection) {
	case 1:
		delivery = false;
		break;
	case 2: 
		delivery = true;
		break;
	case 5:
		delivery = false;
		exit(0);
		break;
	default:
		delivery = false;
		break;
	}
	return delivery;
}

int displayMainMenu() {
	int selection = 4;

	cout << boarder;
	for (string item : mainMenu) { cout << item; }
	cout << boarder;

	selection = getSelection();
	if (selection > 4 && selection < 1)
		selection = 4;
	system("CLS");
	return selection;
}

int displayFreshProduceMenu(vector<Item*>& cart) {
	int selection = 0;
	double pounds = 0;
	int x = 0;
	string tempN, tempP, tempD;

	infile.open("produce.txt");

	vector<string> produceName;
	vector<double> producePrice, produceDiscount;
	

	while (!infile.eof()) {
		getline(infile, tempN);
		getline(infile, tempP);
		getline(infile, tempD);
		produceName.push_back(tempN);
		producePrice.push_back(stod(tempP));
		produceDiscount.push_back(stod(tempD));
		x++;
	}
	x++;
	infile.close();


	while (selection != x) {
		cout << boarder;

		for (int i = 0; i < produceName.capacity(); i++) {
			int num = i + 1;
			tempN = swapLower(produceName[i]);
			cout << "(" << num << ")" << tempN << "\t$" << producePrice[i] << "/lb\n";
		}
		cout << "\n(" << x << ") Return to Main Menu\n ";
		cout << boarder;

		selection = getSelection();

		if (selection !=x) {
			pounds = getPounds();
			selection--;
			FreshProduce* produce = new FreshProduce(produceName[selection], producePrice[selection], pounds, produceDiscount[selection]);
			cart.push_back(produce);
			system("CLS");
		}

	}
	system("CLS");
	return 0;
}

int displayMeatMenu(vector<Item*> &cart) {
	int selection = 0;
	double pounds = 0;
	int x = 0;
	string tempN, tempP, tempD;

	infile.open("meat.txt");

	vector<string> meatName;
	vector<double> meatPrice, meatDiscount;

	while (!infile.eof()) {
		getline(infile, tempN);
		getline(infile, tempP);
		getline(infile, tempD);
		meatName.push_back(tempN);
		meatPrice.push_back(((100 - stod(tempD)) / 100) * stod(tempP));
		meatDiscount.push_back(stod(tempD));
		x++;
	}
	x++;
	infile.close();

	while (selection != x) {
		cout << boarder;

		for (int i = 0; i < meatName.capacity(); i++) {
			int num = i + 1;
			tempN = swapLower(meatName[i]);
			cout << "(" << num << ")" << tempN << "\t$" << meatPrice[i] << "/lb\n";
		}
		cout << "\n(" << x << ") Return to Main Menu\n ";
		cout << boarder;

		selection = getSelection();

		if (selection != x) {
			pounds = getPounds();
			selection--;
			FreshProduce* produce = new FreshProduce(meatName[selection], meatPrice[selection], pounds, meatDiscount[selection]);
			cart.push_back(produce);
			system("CLS");
		}

	}
	system("CLS");
	return 0;
}

int displayFrozenMenu(vector<Item*>& cart) {
	int selection = 0;
	int quantity = 0;
	int x = 0;
	string tempN, tempP, tempD;

	infile.open("frozen.txt");

	vector<string> frozenName;
	vector<double> frozenPrice, frozenDiscount;

	while (!infile.eof()) {
		getline(infile, tempN);
		getline(infile, tempP);
		getline(infile, tempD);
		frozenName.push_back(tempN);
		frozenPrice.push_back(stod(tempP));
		frozenDiscount.push_back(stod(tempD));
		x++;
	}
	x++;
	infile.close();
	
	while (selection != x) {
		cout << boarder;

		for (int i = 0; i < frozenName.capacity(); i++) {
			int num = i + 1;
			tempN = swapLower(frozenName[i]);
			cout << "(" << num << ")" << tempN << "\t$" << frozenPrice[i] << "/lb\n";
		}
		cout << "\n(" << x << ") Return to Main Menu\n ";
		cout << boarder;

		selection = getSelection();

		if (selection != x) {
			quantity = getQuantity();
			selection--;
			MeasuredProduct* frozen = new MeasuredProduct(frozenName[selection], frozenPrice[selection], quantity, frozenDiscount[selection]);
			cart.push_back(frozen);
			system("CLS");
		}

	}
	system("CLS");
	return 0;
}


double getPounds() {
	double pounds;
	cout << "weight of selected item in pounds\n";
	cin >> pounds;
	while (cin.fail()) {
		cout << "Invalid input please enter a number:";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> pounds;
	}
	return pounds;
}

int getQuantity() {
	int quantity;
	cout << "quantity of item\n";
	quantity = getSelection();
	return quantity;
}

int getSelection() {
	int selection;
	cin >> selection;
	while (cin.fail()) {
		cout << "Invalid input please enter a number:";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> selection;
	}
	return selection;
}

string swapLower(string name) {
	string lowerName;
	const char* str = name.c_str();
	
	for (int i = 0;i < name.length();i++) {
		lowerName += tolower(str[i]);
	}
	return lowerName;
}