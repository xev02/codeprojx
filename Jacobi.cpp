#include <iostream>
#include <vector>

int main()
{
	std::vector<int> rownumber = { 2,3,4,5,6,7,8,9,10 }; //This is for declaring a vector.

	int i, j, row, column, iteration, iterationmax; //Line 8 - 12 are for variable and array declarations. 
	float coefficient[10][10];
	float constant[10];
	float sum[10];
	float variable[10];

	std::cout << "Enter the number of rows of the coefficient matrix: \n"; //This prompts the user to input the value for the number of rows. 
	std::cout << "(For an example, enter 3.)\n";
	std::cin >> row; 
	std::cout << "Enter the number of columns of the coefficient matrix: \n"; //This prompts the user to input the value for the number of columns. 
	std::cout << "(For an example, enter 3.)\n";
	std::cin >> column;

	if ((row != column) || (row <= 1 && column <= 1) || (row >= 11 && column >= 11)) //These are the conditions for the program to close.
	{ //'Or' was used so that if any of the conditions are satisfied, the program will detect an invalid input and, thus, close. 
		std::cout << "Invalid input! This program will now close.\n\n"; 
	}

	else if ((row >= rownumber[row - 2] && row <= rownumber[8]) && (column >= rownumber[row - 2] && column <= rownumber[8])) //These are the conditions for the program to run.
	{ //'And' was used to denote a specific range to be used in the conditions. The vector rownumber was called since its elements were used in the range needed for the program.
		std::cout << "Enter the coefficients of the system: \n"; //This prompts the user to input the coefficients of a given matrix. 
		std::cout << "(For an example, enter 5 -2 3; -3 9 1; 2 -1 -7 where the semi-colons substitute for the Enter key.)\n";
		for (i = 0; i < row; i++)
		{

			for (j = 0; j < column; j++)
			{
				std::cin >> coefficient[i][j]; //Following the example, the values this array contain are {5,-2,3;-3,9,1;2,-1,-7}, initially.
												//The semi-colons indicate a new row. 

			}

		}

		std::cout << "Enter the values of the constants: \n"; //This prompts the user to input the constants.
		std::cout << "(For an example, enter -1, 2, 3, in that sequence, without the commas.)\n";
		for (i = 0; i < row; i++)
		{
			std::cin >> constant[i]; //Following the example, the values this array contain are {-1,2,3}, initially. 
		}

		for (i = 1; i <= row; i++)
		{
			std::cout << "Enter initial values for x" << i << ": \n"; //This prompts the user to input initial approximations for the Jacobi method.
			std::cout << "(For an example, enter 0.)\n";
			std::cin >> variable[i - 1]; //Following the example, the values this array contain are {0,0,0}. (variable[0] = 0, variable[1] = 0, variable[2] = 0)
		}

		std::cout << "Enter the number of iterations: \n"; //This prompts the user to input the number of iterations desired for the Jacobi method.
		std::cout << "(For an example, enter 10.)\n";
		std::cin >> iterationmax; //Following the example, this has a value of 10, initially. 

		for (iteration = 1; iteration <= iterationmax; iteration++) //This loop starts from iteration = 1 until the desired number of iterations of the user.
		{
			std::cout << "\nIteration " << iteration << ": ";
			std::cout << "\n---------------------------\n";

			for (i = 0; i < row; i++)
			{
				sum[i] = constant[i]; //The values in the constant array are first initialized to the sum array.
				for (j = 0; j < column; j++) //This for loop inside another for loop is for 'directing' the loop. 
				{
					//In other terms, it means that the program will loop the operations specified on the first element of the first row until the last element,
					//then the first element of the second row until the last element, and so on...until reaching the last row.
					if (i != j) //This if condition excludes all the values in the diagonal section of the coefficient matrix. 
					{//For every element index that satisfies this if condition, the specified operation is performed. 

						sum[i] = sum[i] - coefficient[i][j] * variable[j]; 
						//This sequence of operations merely reflects what is normally done in the Jacobi method on paper. 

						/* Considering a 3x3 coefficient matrix such as in the example, this is only applicable to the following: 
							___ (0,1) (0,2)
							(1,0) ___ (1,2) >>>>>> These are the element indices whose values are being mathematically operated on.
							(2,0) (2,1) ___ 
						*/
					}

				}
			}
			for (i = 0; i < row; i++)
			{
				variable[i] = sum[i] / coefficient[i][i]; //The values for the variable array here are from the sum values from above and
														//the values of the 'untouched' coefficient array values. The coefficient array values
														//here that were 'untouched' are now used as divisors for the values of the sum array.  
				std::cout << " x" << i + 1 << " = " << variable[i] << "\n"; //This prints out the approximate solutions of each iteration. 
			}

			std::cout << "---------------------------\n\n"; //This was placed so as to distinguish the individual iterations done by the program.

		}

	}

	system("pause"); //This doesn't allow the .exe file to close immediately after the program is run. 
}