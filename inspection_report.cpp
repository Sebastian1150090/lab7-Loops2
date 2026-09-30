/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Sebastian A. Feliciano]
 * Lab: 7 - Loops II
 * Description: [This programs tells the cordinator the final lab scores.]
 * Due Date: [9/30/26]
 */
#include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int deviceCount;                                     // Stores the known number of devices in the batch
    int passingDeviceCount = 0;                          // Counts devices with a passing quality score
    double qualityScore;                                 // Stores one device score per iteration
    double totalScore = 0.0;                             // Accumulates all quality scores

    cout << "Enter number of devices from 1 to 10: ";  // Prompts for the batch size
    cin >> deviceCount;                                  // Reads the first batch-size candidate

    while (deviceCount < 1 || deviceCount > 10) {        // Repeats while the batch size is outside the allowed range
        cout << "Invalid device count. Try again: ";    // Explains why another batch size is required
        cin >> deviceCount;                              // Reads a replacement batch size
    }                                                     // Ends after a valid batch size is entered

    for(int device = 1; device <= deviceCount; device++) { // Repeats once for each device in the batch
        cout << "Enter quality score for device " << device << ": "; // Identifies the current device in the prompt
        cin >> qualityScore;                              // Reads one quality score for this iteration
        totalScore += qualityScore;                       // Adds this score to the running total
        if (qualityScore >= 70.0) {                       // Checks whether the score is passing
            passingDeviceCount++;                         // Counts one passing device
            cout << "Device passes inspection." << endl;  // Reports the passing result
        } else {                                          // Handles a failing score
            cout << "Device fails inspection." << endl;   // Reports the failing result
        }                                                 // Ends the selection structure
    }                                                
    double averageScore = totalScore / deviceCount;             // Calculates the average quality score
    cout << fixed << setprecision(2);                    // Formats displayed decimal values with two places
    cout << "Final Inspection Report:" << endl;
    cout << "Total devices inspected: " << deviceCount << endl;
    cout << "Devices passing inspection: " << passingDeviceCount << endl;
    cout << "Average quality score: " << averageScore << endl;

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function

/*
 * Analysis:
 * 1. [TotalScore starts at 0.0. because it is the initial value for the accumulation of all quality scores.]
 * 2. [PassingDeviceCount changes for 70 but not for 69 because 70 is the threshold for passing, while 69 is below that threshold.]
 * 3. [AverageScore is calculated after the for loop because it needs the total score and the count of devices to compute the average, which are only fully known after all devices have been processed.]
 */

 /*
Case 1: deviceCount = 3
Inputs: scores 80.0, 65.0, 70.0

1. Initial accumulator: totalScore = 0.00
2. After each iteration:
   Iteration 1: totalScore = 80.00
   Iteration 2: totalScore = 145.00
   Iteration 3: totalScore = 215.00
3. Counter: passingDeviceCount goes from 0 to 1 on iteration 1 (80 >= 70).
   It does not change on iteration 2 (65 < 70).
   It goes from 1 to 2 on iteration 3 (70 >= 70).
4. Expected final values: passingDeviceCount = 2, totalScore = 215.00,
   average = 215.00 / 3 = 71.67
   Expected output:
     Total devices inspected: 3
     Devices passing inspection: 2
     Average quality score: 71.67
*/
