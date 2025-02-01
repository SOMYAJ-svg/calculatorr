//calculator using operator overloading and if else
#include <iostream>
using namespace std;

class complex {
    float real, imag;

public:
    complex(float real = 0, float imag = 0) {
        this->real = real;
        this->imag = imag;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    complex operator+(complex &obj) {
        return complex(this->real + obj.real, this->imag + obj.imag);
    }

    complex operator-(complex &obj) {
        return complex(this->real - obj.real, this->imag - obj.imag);
    }

    complex operator*(complex &obj) {
        return complex((this->real * obj.real) - (this->imag * obj.imag),
                       (this->real * obj.imag) + (this->imag * obj.real));
    }


    complex operator/(complex &obj) {
        float denominator = obj.real * obj.real + obj.imag * obj.imag;
        if (denominator == 0) {
            cout << "Error: Division by zero!" << endl;
            return complex(); // Return a default complex number
        }
        float realPart = (this->real * obj.real + this->imag * obj.imag) / denominator;
        float imagPart = (this->imag * obj.real - this->real * obj.imag) / denominator;
        return complex(realPart, imagPart);
    }
};

int main() {
    float r1, i1, r2, i2;
    int choice;

    cout << "Enter first complex number (real and imaginary part): ";
    cin >> r1 >> i1;

    cout << "Enter second complex number (real and imaginary part): ";
    cin >> r2 >> i2;

    complex num1(r1, i1), num2(r2, i2), result;

    cout << "\nChoose operation:\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            result = num1 + num2; 
            cout << "\nAddition Result: ";
            result.display();
            break;
        case 2:
            result = num1 - num2; 
            cout << "\nSubtraction Result: ";
            result.display();
            break;
        case 3:
            result = num1 * num2;
            cout << "\nMultiplication Result: ";
            result.display();
            break;
        case 4:
            result = num1 / num2; 
            cout << "\nDivision Result: ";
            result.display();
            break;
        default:
            cout << "\nInvalid choice! Please enter a valid option (1-4)." << endl;
    }

    return 0;
}
