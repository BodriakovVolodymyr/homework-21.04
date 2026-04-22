#pragma once
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Time_.h"
using namespace std;
class Order
{
	static int counter;


	Date orderDate;
	Time_ orderTime;

	int timeToCook;
	string orderDescription;
	double price;
	int orderNumber;

public:
	Order();
	Order(Date date, Time_ time, int _timeToCook, const char* _description, double _price);
	
	
	int getReadyTime() const;
	void showOrder() const;
};

