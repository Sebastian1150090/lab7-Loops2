/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Sebastian A. Feliciano]
 * Lab: 7 - Loops II
 * Description: [This program calculates voltage calibration summary for a given set of data]
 * Due Date: [9/30/26]
 */

 #include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    const double MIN_VOLTAGE = 4.75;                      // Stores the lower accepted voltage limit
    const double MAX_VOLTAGE = 5.25;                      // Stores the upper accepted voltage limit
    int readingCount;                                     // Stores the known number of readings
    int acceptedReadingCount = 0;                         // Counts readings inside the accepted range
    double voltage;                                       // Stores one voltage reading per iteration
    double totalVoltage = 0.0;                            // Accumulates every voltage reading

    cout << "Enter number of readings from 1 to 5: ";   // Prompts for the iteration count
    cin >> readingCount;                                  // Reads the first count candidate

    while (readingCount < 1 || readingCount > 5) {        // Repeats while the count is outside the allowed range
        cout << "Invalid count. Try again: ";           // Explains why another count is required
        cin >> readingCount;                              // Reads a replacement count
    }                                                     // Ends after a valid count is entered

        for (int reading = 1; reading <= readingCount; reading++) { // Repeats once for each requested reading
        cout << "Enter voltage for reading " << reading << ": "; // Identifies the current reading in the prompt
        cin >> voltage;                                   // Reads one voltage for this iteration
        totalVoltage += voltage;                          // Adds this voltage to the running total

        if (voltage >= MIN_VOLTAGE && voltage <= MAX_VOLTAGE) { // Checks whether the reading is within both limits
            acceptedReadingCount++;                       // Counts one accepted reading
            cout << "Reading accepted." << endl;         // Reports the accepted result
        } else {                                          // Handles a reading outside the accepted range
            cout << "Reading requires review." << endl;  // Reports the out-of-range result
        }                                                 // Ends the selection structure
    }                                                     // Ends the count-controlled loop
        double averageVoltage = totalVoltage / readingCount; // Calculates the average after all readings are accumulated

    cout << fixed << setprecision(2);                    // Formats displayed decimal values with two places
    cout << "Total voltage: " << totalVoltage << endl;   // Displays the accumulated voltage total
    cout << "Average voltage: " << averageVoltage << endl; // Displays the calculated average
    cout << "Accepted readings: " << acceptedReadingCount << endl; // Displays the conditional counter

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function