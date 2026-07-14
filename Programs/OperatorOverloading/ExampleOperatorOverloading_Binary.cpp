#include <iostream>
using namespace std;

class Complex {
private:
	float real, imag;
public:
	Complex(float r = 0, float i = 0) : real(r), imag(i) {}
	// ── Overload + ────────────────────────────────────────── // 'this' is c1 (left side), 'c' is c2 (right side)
	Complex operator+(const Complex& c) {
		return Complex(real + c.real, imag + c.imag);
	}

	// ── Overload - ──────────────────────────────────────────
	Complex operator-(const Complex& c) {
		return Complex(real - c.real, imag - c.imag);
	}

	// ── Overload == (returns bool, not Complex) ─────────────
	bool operator==(const Complex& c) {
		return (real == c.real) && (imag == c.imag);
	}
	void display() {
		cout << real << " + " << imag << "i" << endl;
	}
};
int main() {
	Complex c1(3.0, 4.0); // 3 + 4i
	Complex c2(1.5, 2.5); // 1.5 + 2.5i

	Complex c3 = c1 + c2; // calls operator+(c2)
	c3.display(); // 4.5 + 6.5i

	Complex c4 = c1 - c2;
	c4.display(); // 1.5 + 1.5i
	cout << (c1 == c2) << endl; // 0 (false)
	return 0;
}