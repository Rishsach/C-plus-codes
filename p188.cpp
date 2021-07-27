#include <bits/stdc++.h>
using namespace std;

int dp[100][1 << 5][1 << 5];

int countOfNumbers(int index, int evenMask,
				int oddMask, int N)
{

	if (index == N + 1) {

		int countOfEvenDigits
			= __builtin_popcount(evenMask);

		int countOfOddDigits
			= __builtin_popcount(oddMask);

		if (countOfOddDigits
			== countOfEvenDigits) {
			return 1;
		}
		return 0;
	}

	int& val = dp[index][evenMask][oddMask];

	if (val != -1)
		return val;

	val = 0;

	
	if (index == 1) {

		for (int digit = (N == 1 ? 0 : 1);
			digit <= 9; ++digit) {

			
			if (digit & 1) {

				
				val += countOfNumbers(
					index + 1, evenMask,
					oddMask | (1 << (digit / 2)), N);
			}


			else {

				val += countOfNumbers(
					index + 1,
					evenMask | (1 << (digit / 2)),
					oddMask, N);
			}
		}
	}

	
	else {
		for (int digit = 0;
			digit <= 9; ++digit) {

			
			if (digit & 1) {

			
				val += countOfNumbers(
					index + 1, evenMask,
					oddMask | (1 << (digit / 2)), N);
			}

			else {

				val += countOfNumbers(
					index + 1,
					evenMask | (1 << (digit / 2)),
					oddMask, N);
			}
		}
	}

	return val;
}

void countNDigitNumber(int N)
{

	memset(dp, -1, sizeof dp);


	cout << countOfNumbers(1, 0, 0, N);
}


int main()
{
	int N = 3;
	countNDigitNumber(N);

	return 0;
}
