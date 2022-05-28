#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

class Product;
class Combo{
public:
	string name;
	int price;
	Combo() {};
	void Add(Product& product) {
		if(name == "") name = product.name;
		else name += product.name;
	}
	void SetPrice(int price) {
		this->price = price;
	}
	Combo operator+(Product a) {
		Combo temp;
		temp.name = this->name + '+' + a.name;
		return temp;
	}
};
class Product {
public:
	string name;
	int price;
	Product() {
		name = "";
		price = -1;
	}
	Product(const char* name, int price) {
		this->price = price;
		this->name = "";
		for (int i = 0; i < strlen(name); i++) {
			this->name += name[i];
		}
	}
	Combo operator+(Product a) {
		Combo temp;
		temp.name = this->name + '+' + a.name;
		return temp;
	}
};





class Store {
	map<string, int> obj_price;
	int limit;
public:
	Store() : limit(0) {};
	void Add(Product product) {
		obj_price[product.name] = product.price;
	}
	void Add(Combo combo) {
		if (limit < 3) {
			obj_price[combo.name] = combo.price;
			limit++;
		}
	}
	void Buy(const char* name) {
		if (!obj_price.at(name)) cout << name << " is not in store.\n";
		else {

		}
	}
	void PrintReceipt() {
		cout << "      Receipt       " << '\n';
		cout << "====================" << '\n';

		int total = 100;


		cout << "====================" << '\n';
		cout << "Total" << setw(15) << total <<'\n';
		obj_price.clear();
	}
};