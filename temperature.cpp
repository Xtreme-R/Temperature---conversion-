#include <iostream>
#include <iomanip>
#include <vector>
#include <limits> 

using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

void convertTemperature(double value, char unit, vector<string>& history) {
    cout << fixed << setprecision(2);
    if (unit == 'C') {
        double fahrenheit = celsiusToFahrenheit(value);
        double kelvin = celsiusToKelvin(value);
        cout << value << "°C is " << fahrenheit << "°F and " << kelvin << "K." << endl;
        history.push_back(to_string(value) + "°C -> " + to_string(fahrenheit) + "°F, " + to_string(kelvin) + "K");
    } else if (unit == 'F') {
        double celsius = fahrenheitToCelsius(value);
        double kelvin = fahrenheitToKelvin(value);
        cout << value << "°F is " << celsius << "°C and " << kelvin << "K." << endl;
        history.push_back(to_string(value) + "°F -> " + to_string(celsius) + "°C, " + to_string(kelvin) + "K");
    } else if (unit == 'K') {
        double celsius = kelvinToCelsius(value);
        double fahrenheit = kelvinToFahrenheit(value);
        cout << value << "K is " << celsius << "°C and " << fahrenheit << "°F." << endl;
        history.push_back(to_string(value) + "K -> " + to_string(celsius) + "°C, " + to_string(fahrenheit) + "°F");
    } else {
        cout << "Invalid unit. Please enter 'C', 'F', or 'K'." << endl;
    }
}

int main() {
    cout << "Temperature Converter with History Log" << endl;

    double value;
    char unit;
    vector<string> history;
    char choice;

    do {
        cout << "Enter the temperature value: ";
        while (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a numeric temperature value: ";
        }

        cout << "Enter the unit of the temperature (C for Celsius, F for Fahrenheit, K for Kelvin): ";
        cin >> unit;
        unit = toupper(unit);

        convertTemperature(value, unit, history);

        cout << "Do you want to perform another conversion? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);

    } while (choice == 'Y');

    cout << "\nConversion History:" << endl;
    for (const string& record : history) {
        cout << record << endl;
    }

    return 0;
}
