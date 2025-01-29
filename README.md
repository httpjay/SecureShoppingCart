# SecureShoppingCart
Secure C++ shopping cart system with validation and unit tests. 🚀

# Shopping Cart System

## Overview
This is a secure C++ implementation of a shopping cart system with unit tests. The project is structured into multiple files for modularity and ease of maintenance.

## File Structure
```
/shopping_cart_project
│── shopping_cart.h        # Header file (class declaration)
│── shopping_cart.cpp      # Implementation file (class definition)
│── test_shopping_cart.cpp # Unit testing file
│── README.md              # Documentation (this file)
```

## File Descriptions
### 1. `shopping_cart.h`
- Declares the `ShoppingCart` class.
- Defines private attributes like `id`, `customer_id`, and `items`.
- Declares member functions for adding, removing items, and calculating total cost.

### 2. `shopping_cart.cpp`
- Implements the `ShoppingCart` class.
- Provides logic for:
  - Generating unique cart IDs (UUIDs).
  - Validating customer ID formats.
  - Ensuring items exist in the catalog.
  - Preventing invalid item quantities.

### 3. `test_shopping_cart.cpp`
- Contains unit tests for the `ShoppingCart` class.
- Tests:
  - Valid item addition and removal.
  - Correct total cost calculation.
  - Handling of invalid inputs (e.g., invalid customer IDs, negative quantities, non-existent items).
- Uses `assert()` for test validation.
  

## Prerequisites
Ensure you have:
- **g++ (GCC compiler)** installed.
- **A terminal or command prompt** for executing commands.

## Installation & Usage
Follow these steps to run the program:

### **Step 1: Clone the Repository**
```sh
git clone https://github.com/your-username/shopping-cart.git
cd shopping-cart
```

### **Step 2: Compile the Code**
```sh
g++ -o test_shopping_cart shopping_cart.cpp test_shopping_cart.cpp
```

### **Step 3: Run the Program**
#### **For Windows (Command Prompt or PowerShell):**
```sh
test_shopping_cart.exe
```
#### **For Linux/macOS (Terminal):**
```sh
./test_shopping_cart
```

### **Step 4: Expected Output**
If the tests pass, you should see:

```
All tests passed successfully!
```
### **Example Output Screenshot**
Below is an example of the test run output:


![Screenshot (135)](https://github.com/user-attachments/assets/bc52b34e-ca21-4065-9f07-60b0b0f454cf)



If there is an error, the program will display the corresponding error message.

## Troubleshooting
### **Issue: `g++: command not found`**
- Ensure GCC is installed:
  - **Windows:** Install MinGW and add it to PATH.
  - **Linux/macOS:** Install via package manager:
    ```sh
    sudo apt install g++   # Ubuntu/Debian
    brew install gcc       # macOS
    ```

### **Issue: `No such file or directory` during compilation**
- Ensure you're in the correct project directory (`cd shopping-cart`).
- Use `dir` (Windows) or `ls` (Linux/macOS) to list available files.

### **Issue: `Permission denied` when running the program**
- Give execute permission (Linux/macOS):
  ```sh
  chmod +x test_shopping_cart
  ```
  Then run:
  ```sh
  ./test_shopping_cart
  ```
Acknowledgments

This project was developed with the assistance of ChatGPT, which provided guidance on structuring, implementing, and troubleshooting the C++ shopping cart system.

## Contribution
If you want to contribute:
1. Fork the repository.
2. Create a feature branch: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m "Description of changes"`.
4. Push to your fork: `git push origin feature-name`.
5. Create a pull request.

---

**Now you’re ready to use and test the Shopping Cart System!** 🚀

