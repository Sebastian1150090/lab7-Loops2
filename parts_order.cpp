/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Sebastian A. Feliciano]
 * Lab: 7 - Loops II
 * Description: [This program calculates parts orders for a given set of data]
 * Due Date: [9/30/26]
 */

 #include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int requestCount;                                    // Stores the known number of part requests
    int partChoice;                                      // Stores one menu selection
    int quantity;                                        // Stores the requested quantity for one part
    int validLineCount = 0;                              // Counts requests that have a valid part and quantity
    double unitPrice;                                    // Stores the price selected by the switch
    double lineCost;                                     // Stores the cost of one valid request
    double orderTotal = 0.0;                             // Accumulates all valid line costs
    bool isValidPartChoice;                              // Tracks whether the switch selected a real part

    cout << "Enter number of part requests from 1 to 5: "; // Prompts for the iteration count
    cin >> requestCount;                                 // Reads the first request-count candidate

    // TODO: Validate requestCount with a while loop before processing requests.
    while (requestCount < 1 || requestCount > 5) {        // Keep asking while the count is below 1 or above 5.
        cout << "Invalid request count. Try again: ";   // Explains why another count is required
        cin >> requestCount;                             // Reads a replacement count
    }                                                    // Ends after a valid count is entered

    // TODO: Write the for loop header that processes request 1 through requestCount.
    for (int request = 1; request <= requestCount; request++) { // Repeats once for each requested part        
        // TODO: Reset isValidPartChoice to true.
        isValidPartChoice = true;
          cout << endl << "Request " << request << " of " << requestCount << endl;
        cout << "1. Bolt    ($3.25)" << endl;
        cout << "2. Nut     ($4.50)" << endl;
        cout << "3. Washer  ($1.75)" << endl;
        cout << "Enter part choice (1-3): ";
        cin >> partChoice;
        // TODO: Use a while loop to ask again while partChoice is below 1 or above 3.
        while (partChoice < 1 || partChoice > 3) {
            cout << "Invalid part choice. Try again: ";
            cin >> partChoice;
        }
   
        // TODO: Use switch to assign unitPrice and display the selected part.
        switch (partChoice) {
            case 1:
                unitPrice = 3.25;
                cout << "Part 1 selected." << endl;
                break;
            case 2:
                unitPrice = 4.50;
                cout << "Part 2 selected." << endl;
                break;
            case 3:
                unitPrice = 1.75;
                cout << "Part 3 selected." << endl;
                break;
            default:
                isValidPartChoice = false; // Defensive programming: should not happen due to validation.
                cout << "Invalid part choice encountered." << endl;
                break;
        }
        // TODO: For a valid part choice, prompt for quantity and use if/else.
        // Accept quantities from 1 to 5 and update lineCost, orderTotal, and validLineCount.
        if (isValidPartChoice) {
            cout << "Enter quantity (1-5): ";
            cin >> quantity;
            if (quantity >= 1 && quantity <= 5) {
                lineCost = unitPrice * quantity;
                orderTotal += lineCost;
                validLineCount++;
                cout << "Line cost: $" << fixed << setprecision(2) << lineCost << endl;
            } else {
                cout << "Invalid quantity. Request skipped." << endl;
            }
        } else {
            cout << "Request skipped due to invalid part choice." << endl;
        }
        // Otherwise, report that the request was skipped.
    }

    // TODO: After the for loop, format and display validLineCount and orderTotal.
    cout << fixed << setprecision(2);
    cout << "Valid lines: " << validLineCount << endl;
    cout << "Order total: $" << orderTotal << endl;

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function

/*
 * Test analysis:
 * 1. [OrderTotal starts at 0.0 because it is the initial value for the accumulation of all valid line costs.]
 * 2. [Invalid part choice asks for another menu selection because the while loop checks for valid input and prompts again if the input is outside the range of 1 to 3.]
 * 3. [IsValidPartChoice is reset during every for iteration because each request is independent, and we need to ensure that the validity of the part choice is evaluated fresh for each new request.]
 * 4. [Invalid quantity does not change validLineCount because the if/else structure only increments validLineCount when a valid quantity is entered, and invalid quantities are skipped without affecting the count.]
 */
/*
Case 1: requestCount = 2
Inputs: part 1 quantity 2; part 3 quantity 1

1. Initial accumulator: orderTotal = 0.00
2. After each iteration:
   Iteration 1: orderTotal = 6.50
   Iteration 2: orderTotal = 8.25
3. Counter: validLineCount goes from 0 to 1 and from 1 to 2 because
   the quantities are valid. It does not change if the quantity is invalid.
4. Expected final value: validLineCount = 2, orderTotal = 8.25
*/