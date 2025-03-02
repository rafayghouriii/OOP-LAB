#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MenuItem {
    string itemName;
    string category;
    double price;

public:
    MenuItem(string name, string type, double cost)
	{
        itemName=name;
        category=type;
        price=cost;
    }

    string getName()
	{
		return itemName;
	}
    double getPrice()
	{
		return price;
	}
    string getCategory()
	{
	return category;
	}
};

class CoffeeShop {
    string shopName;
    vector<MenuItem> menu;
    vector<string> orderList;
public:
    CoffeeShop(string name) : shopName(name)
	{
        menu = {
            MenuItem("espresso", "drink", 2.60),
            MenuItem("cappuccino", "drink", 2.00),
            MenuItem("muffin", "food", 3.00),
            MenuItem("croissant", "food", 1.50),
            MenuItem("latte", "drink", 4.50)
        };
    }

    void addOrder(string order)
	{
        for (const auto& item : menu)
		{
            if (order == item.getName())
			{
                orderList.push_back(order);
                cout << order << " has been added!" << endl;
                return;
            }
        }
        cout << "Sorry, we don't have that item available." << endl;
    }

    void processOrder()
	{
        if (!orderList.empty())
		{
            cout << "Your " << orderList.front() << " is ready!" << endl;
            orderList.erase(orderList.begin());
        } else
		{
            cout << "No pending orders." << endl;
        }
    }

    void showOrders()
	{
        if (orderList.empty())
		{
            cout << "No orders placed yet." << endl;
        } else
		{
            cout << "Current orders:" << endl;
            for (const auto& order : orderList)
			{
                cout << order << endl;
            }
        }
    }

    double calculateBill()
	{
        double total = 0;
        for (const auto& order : orderList)
		{
            for (const auto& item : menu)
			{
                if (order == item.getName())
				{
                    total += item.getPrice();
                }
            }
        }
        return total;
    }

    string findCheapest()
	{
        MenuItem cheapest = menu[0];
        for (const auto& item : menu)
		{
            if (item.getPrice() < cheapest.getPrice())
			{
                cheapest = item;
            }
        }
        return cheapest.getName();
    }

    void showDrinks()
	{
        cout << "Available drinks:" << endl;
        for (const auto& item : menu)
		{
            if (item.getCategory() == "drink")
			{
                cout << item.getName() << endl;
            }
        }
    }

    void showFood()
	{
        cout << "Available food items:" << endl;
        for (const auto& item : menu)
		{
            if (item.getCategory() == "food")
			{
                cout << item.getName() << endl;
            }
        }
    }
};

int main()
{
    CoffeeShop cafe("Cafe Ridan");
    int option;
    while (true) {
        cout << "\nCafe Menu:" << endl;
        cout << "1. Place an order" << endl;
        cout << "2. Serve an order" << endl;
        cout << "3. Show pending orders" << endl;
        cout << "4. Check total bill" << endl;
        cout << "5. Find cheapest item" << endl;
        cout << "6. Show drinks" << endl;
        cout << "7. Show food" << endl;
        cout << "8. Exit" << endl;
        cout << "Select an option: ";
        cin >> option;
        cin.ignore();

        string order;
        
        switch (option) {
        case 1:
            cout << "Enter item name: ";
            getline(cin, order);
            cafe.addOrder(order);
            break;
        case 2:
            cafe.processOrder();
            break;
        case 3:
            cafe.showOrders();
            break;
        case 4:
            cout << "Total amount due: $" << cafe.calculateBill() << endl;
            break;
        case 5:
            cout << "Cheapest item: " << cafe.findCheapest() << endl;
            break;
        case 6:
            cafe.showDrinks();
            break;
        case 7:
            cafe.showFood();
            break;
        case 8:
            cout << "Exiting. Have a great day!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    }
}

