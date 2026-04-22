#include "OrderSystem.h"
#include <algorithm>

void OrderSystem::addOrder(const Order& order)
{
	orders.push_back(order);
}

void OrderSystem::Sort_by_time()
{
	sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
		return a.getReadyTime() < b.getReadyTime();
		});
}

void OrderSystem::FirstOrderComplate()
{
	if (orders.empty())
	{
		cout << "No orders to complete." << endl;
		return;
	}
	cout << "Completing order: ";
	orders[0].showOrder();
	orders.erase(orders.begin());

}

void OrderSystem::showAllOrders() const
{
	for(const auto& ord : orders)
		ord.showOrder();
}


