
#include <iostream>

class Widget {
public:
	Widget() { ++count; }
	~Widget() { --count; }

	static int getCount() { return count; }

private:
	// static data member shared by all instances
	static int count;
};

// define and initialize the static data member
int Widget::count = 0;

int main() {
	std::cout << "Initial count: " << Widget::getCount() << '\n';
	Widget a;
	std::cout << "After creating a: " << Widget::getCount() << '\n';
	{
		Widget b, c;
		std::cout << "Inside block (a,b,c): " << Widget::getCount() << '\n';
	}
	std::cout << "After block (b,c destroyed): " << Widget::getCount() << '\n';
	return 0;
}
