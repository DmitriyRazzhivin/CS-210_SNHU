/*
 * Calculator.cpp

 *	Description: Module Two Calculator Debugging Assignment.
 *  Date: 05/17/2026
 *  Author: Dmitriy Razzhivin
 
 */

#include <iostream>

using namespace std;

int main() // FIX: Changed return type from void to int.
{
	//FIX: Removed char statement[100] since it was never used and has a possible memory leak.
	double op1, op2; // FIX: Changed data types from int to double to handle floating-point calculations
	char operation;
	char answer ='y'; // FIX: Assigned single character with single quotes and added a missing semicolon

	while (answer == 'y' || answer == 'Y') // FIX: Updated condition to evaluate both uppercase 'Y' and lowercase 'y'
	{
		cout << "Enter expression" <<endl;
		cin >> op1 >> operation >> op2; // FIX: Adjusted input sequence order to ensure op1 represents the first input number

		if (operation == '+') // FIX: Removed trailing semicolons, fixed string operators (<<), and updated logic strings
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
		else if(operation == '-') // FIX: Chnaged single if-statments into if - else if stements. So only one condition is checked.
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
		else if(operation == '*')
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
		else if (operation == '/')
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;

		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;	
		
        if (answer == 'n' || answer == 'N') // Explicitly check for 'N' or 'n' to handle a clean exit notice
            break; // Immediately exits the while loop
	}// End of while loop

	// FIX: Moved termination text outside of the loop to run only when exiting the program
	cout << "Program Finished." << endl;

	return 0;
}