
#include <bits/stdc++.h>
using namespace std;

bool isInterleaved (char A[], char B[], char C[])
{
	
	while (*C != 0)
	{
		if (*A == *C)
			A++;

		
		else if (*B == *C)
			B++;

		
		else
			return false;
		

		C++;
	}


	if (*A || *B)
		return false;

	return true;
}

int main()
{
	char A[] = "AB";
	char B[] = "CD";
	char C[] = "ACBG";
	if (isInterleaved(A, B, C) == true)
		cout << C << " is interleaved of " << A << " and " << B;
	else
		cout << C << " is not interleaved of " << A << " and " << B;

	return 0;
}


