#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <stdexcept>
#include <random>
#include <sstream>
#include <cmath>

using namespace std;

class ShoppingCart {
private:
    const string id; // Immutable UUID for the cart
    const string customer_id; // Immutable customer ID
    unordered_map<string, int> items; // Items with quantities

    static string generateUUID();
    static bool isValidCustomerID(const string& customer_id);

    const unordered_map<string, double> catalog = {
        {"item1", 10.99},
        {"item2", 5.49},
        {"item3", 20.00}
    };

public:
    ShoppingCart(const string& customer_id);

    string getId() const;
    string getCustomerId() const;
    unordered_map<string, int> getItems() const;
    void addItem(const string& item, int quantity);
    void removeItem(const string& item);
    double getTotalCost() const;
};

#endif
