#include "Order.h"
int Order::counter = 0;
Order::Order()
{
	timeToCook = 0;
    orderDescription = "No info";
    price = 0;
	orderNumber = ++counter;
}

Order::Order(Date date, Time_ time, int _timeToCook, const char* _description, double _price)
{
	this->orderDate = date;
	this->orderTime = time;
	this->timeToCook = _timeToCook;
	this->orderDescription = _description;
	this->price = _price;
	this->orderNumber = ++counter;
}

int Order::getReadyTime() const
{
    return orderTime.getHour()*60 + orderTime.getMinutes() + timeToCook;
}

void Order::showOrder() const
{
    cout << "Order Number: " << orderNumber << endl;
    cout << "Order Date: ";
    orderDate.showDate();
    cout << "Order Time: ";
    orderTime.showTime();
    cout << "Time to Cook: " << timeToCook << " minutes" << endl;
    cout << "Order Description: " << orderDescription << endl;
    cout << "Price: " << price << "UAH" << endl;
    cout << endl;
}