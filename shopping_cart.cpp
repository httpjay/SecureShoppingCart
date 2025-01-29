#include "shopping_cart.h"

string ShoppingCart::generateUUID() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 15);
    uniform_int_distribution<> dis2(8, 11);

    stringstream ss;
    ss << hex;
    for (int i = 0; i < 8; ++i) ss << dis(gen);
    ss << "-";
    for (int i = 0; i < 4; ++i) ss << dis(gen);
    ss << "-4"; // UUID version 4
    for (int i = 0; i < 3; ++i) ss << dis(gen);
    ss << "-";
    ss << dis2(gen); // UUID variant
    for (int i = 0; i < 3; ++i) ss << dis(gen);
    ss << "-";
    for (int i = 0; i < 12; ++i) ss << dis(gen);
    return ss.str();
}

bool ShoppingCart::isValidCustomerID(const string& customer_id) {
    const regex pattern("^[A-Z]{3}[0-9]{5}[A-Z]{2}[-][AQ]$");
    return regex_match(customer_id, pattern);
}

ShoppingCart::ShoppingCart(const string& customer_id) : id(generateUUID()), customer_id(customer_id) {
    if (!isValidCustomerID(customer_id)) {
        throw invalid_argument("Invalid customer ID format.");
    }
}

string ShoppingCart::getId() const {
    return id;
}

string ShoppingCart::getCustomerId() const {
    return customer_id;
}

unordered_map<string, int> ShoppingCart::getItems() const {
    return items;
}

void ShoppingCart::addItem(const string& item, int quantity) {
    if (catalog.find(item) == catalog.end()) {
        throw invalid_argument("Item not found in catalog.");
    }
    if (quantity <= 0 || quantity > 100) {
        throw invalid_argument("Quantity must be between 1 and 100.");
    }
    items[item] = quantity;
}

void ShoppingCart::removeItem(const string& item) {
    if (items.find(item) == items.end()) {
        throw invalid_argument("Item not found in the cart.");
    }
    items.erase(item);
}

double ShoppingCart::getTotalCost() const {
    double total = 0.0;
    for (const auto& [item, quantity] : items) {
        total += catalog.at(item) * quantity;
    }
    return total;
}
