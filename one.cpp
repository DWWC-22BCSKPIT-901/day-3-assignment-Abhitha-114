#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 0 || n > 30) {
        cout << "Input should be in the range 0 <= n <= 30." << endl;
        return 1;
    }

    cout << "Fibonacci number F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
