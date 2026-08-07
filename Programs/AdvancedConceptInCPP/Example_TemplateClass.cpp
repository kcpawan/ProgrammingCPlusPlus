#include <iostream>
#include <string>
using namespace std;

// Define a template class
template <typename T>
class Box {
private:
    T content;
    
public:
    // Constructor
    Box(T item) : content(item) {}
    
    // Getter
    T getContent() const { return content; }
    
    // Setter
    void setContent(T item) { content = item; }
    
    // Display
    void display() const {
        cout << "Content: " << content << endl;
    }
};

// Usage
int main() {
    // Box for integers
    Box<int> intBox(42);
    intBox.display();
    
    // Box for strings
    Box<string> strBox("Hello World");
    strBox.display();
    
    // Box for doubles
    Box<double> doubleBox(3.14159);
    doubleBox.display();
    
    return 0;
}