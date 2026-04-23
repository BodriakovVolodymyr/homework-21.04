#include "OrderSystem.h"
#include <string>
int main()
{
    OrderSystem system;




    int menu;
    do {
        cout << "Menu:\n";
        cout << "1. Add order\n";
        cout << "2. Show all orders\n";
        cout << "3. Sort orders by time\n";
        cout << "4. Complete first order\n";
        cout << "0. Exit\n";
        cin >> menu;

        switch (menu) {
        case 0:
            cout << "Exiting...\n";
            break;
        case 1:
        {
            int timeToCook;
            string description;
            double price;
            Date orderDate;
            Time_ orderTime;
            cout << "Enter time to cook (in minutes): ";
            cin >> timeToCook;
            cout << "Enter order description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Enter price: ";
            cin >> price;

            system.addOrder(Order(orderDate, orderTime, timeToCook, description.c_str(), price));
        }break;
        case 2:
        {
            system.showAllOrders();
        }break;
        case 3:
        {
            system.Sort_by_time();
            cout << "Orders sorted by time.\n";
        }break;
        case 4:
        {
            system.FirstOrderComplate();
            cout << "First order completed.\n";
        }break;
        }

    } while (menu != 0);
    }