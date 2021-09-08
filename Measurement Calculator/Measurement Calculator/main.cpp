//
//  main.cpp
//  Measurement Calculator
//
//  Created by Amir on 8/7/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector<double> x;
    string unit;
    double sum = 0;
    double prev;
    double temp;
    double smallest = 0;
    double largest = 0;
    int counter = 0;
    while (true) {
        cout << "Enter a double followed by a space and a unit [cm, in, ft, m]\nEnter = to calculate: ";
        cin >> temp;
        cin >> unit;
        if (!cin)
            break;
        if (unit == "cm" || unit == "in" || unit == "ft" || unit == "m") {
            x.push_back(temp);
            if (counter == 0) {
                smallest = temp;
                largest = temp;
                cout << temp << " is the first so far.\n";
            }
            else {
                if (temp > largest) {
                    largest = temp;
                    cout << temp << " is the largest so far.\n";
                }
                else if (temp < smallest) {
                    smallest = temp;
                    cout << temp << " is the smallest so far.\n";
                }
            }
            prev = temp;
            if (unit == "cm") {
                sum += temp/100;
            }
            else if (unit == "in") {
                sum += temp/39.37;
            }
            else if (unit == "ft") {
                sum += temp/3.281;
            }
            else if (unit == "m") {
                sum += temp;
            }
            ++counter;
        }
        else break;
    }
    cout << "Smallest number: " << smallest << "\nLargest number: " << largest << "\nNumber of values: "
    << counter << "\nSum of values: " << sum << "\nValues: ";
    sort(x.begin(), x.end());
    for (int i : x) {
        cout << i << " ";
    }
    cout << "\n";
}
