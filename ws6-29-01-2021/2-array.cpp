// 2 functions with an array argument

/* If you pass an ordinary variable, the function works with a copy.
   But if you pass an array, the function works with the original. */

/* Talk about protection of the array using the const keyword */

#include <iostream>
const int ARRAY_SIZE = 8;

int sumArray(const int arr[], int n);

int main()
{
	// each position marks the number of cookies a person eats!
	int cookies[ARRAY_SIZE] = {1, 2, 4, 8, 16, 32, 64, 128};

	int sum = sumArray(cookies, ARRAY_SIZE);

	std :: cout << "Total cookies eaten: " << sum << "\n";

	//TODO Uncomment the line below and check with the students 
	std :: cout << " A hack! The first person now says it took " << cookies[0] << " cookies" << std :: endl;

	return 0;
}

// return the sum of an integer array (and tries to set the first value of the array to 0 --- fix with const).
int sumArray(const int arr[], int n) 
{
	int total = 0;
	for (int i = 0; i < n; i++)
		total = total + arr[i];

	arr[0] = 0;

	return total;
}