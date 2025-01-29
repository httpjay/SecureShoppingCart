#include "shopping_cart.h"
#include <cassert>

void testShoppingCart() {
    try {
        ShoppingCart cart("ABC12345XY-A");

        // Test adding valid items
        cart.addItem("item1", 2);
        cart.addItem("item2", 5);

        // Test total cost
        double total = cart.getTotalCost();
        double expected_total = 2 * 10.99 + 5 * 5.49;
        assert(fabs(total - expected_total) < 1e-6); // Use a small tolerance for comparison

        // Test removing an item
        cart.removeItem("item1");
        assert(cart.getItems().size() == 1);

        // Test invalid customer ID
        try {
            ShoppingCart invalidCart("INVALID");
        } catch (const invalid_argument& e) {
            assert(string(e.what()) == "Invalid customer ID format.");
        }

        // Test invalid item addition
        try {
            cart.addItem("nonexistent", 1);
        } catch (const invalid_argument& e) {
            assert(string(e.what()) == "Item not found in catalog.");
        }

        // Test invalid quantity
        try {
            cart.addItem("item1", 0);
        } catch (const invalid_argument& e) {
            assert(string(e.what()) == "Quantity must be between 1 and 100.");
        }

        cout << "All tests passed successfully!\n";

    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << '\n';
    }
}

int main() {
    testShoppingCart();
    return 0;
}
