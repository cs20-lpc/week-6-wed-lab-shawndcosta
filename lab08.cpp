#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned, int);
unsigned fib(unsigned, unsigned, unsigned);
unsigned mult(unsigned, unsigned, int);
unsigned power(unsigned, unsigned, int);
unsigned product(unsigned, unsigned, int);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000, 0) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10, 1) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15, 1) << endl;
    cout << "10! = " << fact(10, 1) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50, 0, 1) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned fact(unsigned n, int acc = 1) {
    // base cases (combined)
    if (n <= 1) {
        return 1;
    }

    // recursive case
    return fact(n - 1, n * acc);
}

unsigned fib(unsigned n, unsigned a = 0, unsigned b = 1) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fib(n - 1, b, a + b);
}


unsigned mult(unsigned x, unsigned y, int acc = 0) {
    // base case
    if (y == 0) {
        return acc;
    }

    // recursive case
    return mult(x, y - 1, acc + x);
}

unsigned power(unsigned x, unsigned y, int acc = 1) {
    // base case
    if (y == 0) {
        return acc;
    }

    // recursive case
    return power(x, y - 1, acc * x);
}

unsigned product(unsigned x, unsigned y, int acc = 1) {
    // base case
    if (x == y) {
        return acc * x;
    }

    // recursive case
    return product(x + 1, y, acc * x);
}




// unsigned product(unsigned x, unsigned y) {
//     // base case
//     if (x == y) {
//         return x;
//     }

//     // recursive case
//     unsigned p = product(x + 1, y);
//     return p * x;
// }
