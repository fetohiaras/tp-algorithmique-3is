#include <iostream>
using namespace std;

// Recursive function to calculate the GCD (Greatest Common Divisor) of two integers
int gcd(int a, int b) {
    // Base case
    if (b == 0)
        return a;
    // Recursive case
    else
        return gcd(b, a % b);
}

int main() {
    int a, b;

    cout << "=== GCD Calculator ===" << endl;
    cout << "Enter the first integer: ";
    cin >> a;
    cout << "Enter the second integer: ";
    cin >> b;

    cout << "The GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;

    return 0;
}
