#include "OrderSystem.h"

int main()
{
    OrderSystem system;

    Date d1(21, 4, 2026);
    Time_ t1(10, 30, 0);

    Date d2(21, 4, 2026);
    Time_ t2(10, 35, 0);

    Date d3(21, 4, 2026);
    Time_ t3(10, 45, 0);

    system.addOrder(Order(d1, t1, 20, "Pizza", 150));
    system.addOrder(Order(d2, t2, 15, "Burger", 120));
    system.addOrder(Order(d3, t3, 5, "Coffee", 50));

    system.showAllOrders();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Before sorting:\n";
    system.showAllOrders();

    system.Sort_by_time();

    cout << "\nAfter sorting:\n";
    system.showAllOrders();

    system.FirstOrderComplate();

    cout << "\nAfter completing:\n";
    system.showAllOrders();
}