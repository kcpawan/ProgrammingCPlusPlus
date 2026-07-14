#include <iostream>
using namespace std;

class Inventory {
public:
    int items = 10;
};

// Destination Class
class Product {
private:
    int count;
    
public:
    Product() : count(0) {}
    
    // Constructor handles: Inventory -> Product conversion
    Product(const Inventory& inv) {
        count = inv.items;
    }
    
    // Getter for count
    int getCount() const {
        return count;
    }
    
    // Display product details
    void display() const {
        cout << "Product count: " << count << endl;
    }
};

// Function that takes a Product parameter
void processProduct(Product p) {
    cout << "Processing product..." << endl;
    p.display();
}

int main() {
    cout << "=== Inventory to Product Conversion Demo ===" << endl << endl;
    
    // Create an Inventory object
    Inventory inv;
    cout << "Inventory items: " << inv.items << endl;
    
    // Method 1: Implicit conversion using assignment
    cout << "\n--- Method 1: Implicit Conversion ---" << endl;
    Product p1 = inv;           // Implicit conversion
    p1.display();
    
    // Method 2: Explicit constructor call
    cout << "\n--- Method 2: Explicit Constructor Call ---" << endl;
    Product p2(inv);            // Direct initialization
    p2.display();
    
    // Method 3: Explicit conversion using functional notation
    cout << "\n--- Method 3: Explicit Conversion ---" << endl;
    Product p3 = Product(inv);  // Explicit conversion
    p3.display();
    
    // Method 4: Passing to a function (implicit conversion)
    cout << "\n--- Method 4: Function Parameter Conversion ---" << endl;
    processProduct(inv);        // Implicit conversion in function call
    
    // Demonstrate that multiple products can be created from same inventory
    cout << "\n--- Multiple Products from Same Inventory ---" << endl;
    Product products[3] = {inv, inv, inv};
    for(int i = 0; i < 3; i++) {
        cout << "Product " << i + 1 << ": ";
        products[i].display();
    }
    
    // Show the difference between explicit and implicit
    cout << "\n--- Type Information ---" << endl;
    cout << "Size of Inventory: " << sizeof(Inventory) << " bytes" << endl;
    cout << "Size of Product: " << sizeof(Product) << " bytes" << endl;
    
    return 0;
}