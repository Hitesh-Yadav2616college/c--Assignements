/*As a programmer you need to design a object oriented solution using Inheritance for a restaurant billing application.
 Try to imagine real life scenarion and then make this application*/

#include <iostream>
#include <string>
#define MAX_ITEMS 10
using namespace std;

class MenuItem {
protected:
    string name;
    double price;
    string description;

public:
    MenuItem(string name, double price, string description) : name(name), price(price), description(description) {}

    double getPrice() {
        return price;
    }

    string getName() {
        return name;
    }

    string getDescription() {
        return description;
    }
};

class FoodItem : public MenuItem {
private:
    string ingredients;

public:
    FoodItem(string name, double price, string description, string ingredients)
        : MenuItem(name, price, description), ingredients(ingredients) {}

    string getIngredients() {
        return ingredients;
    }
};

class DrinkItem : public MenuItem {
private:
    double volume; // in liters

public:
    DrinkItem(string name, double price, string description, double volume)
        : MenuItem(name, price, description), volume(volume) {}

    double getVolume() {
        return volume;
    }
};

class Order {
private:
    MenuItem* items[MAX_ITEMS];
    int itemCount;

public:
    Order() : itemCount(0) {}

    void addItem(MenuItem* item) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = item;
        } else {
            cout << "Cannot add more items to the order. Maximum limit reached." << endl;
        }
    }

    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i]->getPrice();
        }
        return total;
    }

    void generateBill() {
        cout << "Order Details:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << items[i]->getName() << ": $" << items[i]->getPrice() << endl;
        }
        cout << "Total: $" << calculateTotal() << endl;
    }
};

int main() {
    FoodItem pizza("Pizza", 12.99, "Delicious pizza with cheese and toppings", "Dough, Cheese, Tomato Sauce, Toppings");
    DrinkItem coke("Coke", 2.49, "Refreshing carbonated beverage", 0.5);

    Order order;
    order.addItem(&pizza);
    order.addItem(&coke);

    order.generateBill();

    return 0;
}