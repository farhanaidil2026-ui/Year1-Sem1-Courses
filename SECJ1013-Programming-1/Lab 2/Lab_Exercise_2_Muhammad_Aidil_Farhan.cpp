/*
Muhammad Aidil Farhan Bin Zamri
A25CS0260
11 / 11 / 2025
Set 1
*/

#include <iostream>
using namespace std;

int main() {
    int number;
    int sum = 0, digit = 0;
    string mo3 = "multiples of 3";
    string mo4 = "multiples of 4";
    string mo5 = "multiples of 5";

    bool multiple3 = false, multiple4 = false, multiple5 = false, multipleAll = false;

    cout << "Enter an integer number: " << endl;
    cin >> number;

    int originalNumber = number;

    while (number > 0) {
        digit = number % 10;
        sum = digit + sum;
        number = number / 10;
    }

    number = originalNumber;
    while (number > 0) {
        digit = number % 10;
        number = number / 10;
        
        if (number > 0) {
            cout << digit << " + ";
        } else {
            cout << digit << " = ";
        }
    }
    cout << sum << endl;

    multiple3 = (sum % 3 == 0);
    multiple4 = (sum % 4 == 0);
    multiple5 = (sum % 5 == 0);
    multipleAll = multiple3 && multiple4 && multiple5;

    if (multipleAll) {
        cout << sum << " is " << mo3 << ", " << mo4 << " and " << mo5 << endl;
    } else if (multiple3 && multiple4) {
        cout << sum << " is " << mo3 << " and " << mo4 << endl;
    } else if (multiple3 && multiple5) {
        cout << sum << " is " << mo3 << " and " << mo5 << endl;
    } else if (multiple4 && multiple5) {
        cout << sum << " is " << mo4 << " and " << mo5 << endl;
    } else if (multiple3) {
        cout << sum << " is " << mo3 << endl;
    } else if (multiple4) {
        cout << sum << " is " << mo4 << endl;
    } else if (multiple5) {
        cout << sum << " is " << mo5 << endl;
    } else {
        cout << sum << " is not multiples of 3, 4 or 5" << endl;
    }

    return 0;
}