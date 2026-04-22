#pragma once
#include "Order.h"
#include<vector>

class OrderSystem
{
	vector<Order>orders;
	
public:
		
	void addOrder(const Order& order);
	void Sort_by_time();
	void FirstOrderComplate();
	void showAllOrders() const;



};

