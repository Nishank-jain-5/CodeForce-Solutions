#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long a, b, n;
		// Read the maximum timer value 'a', initial timer value 'b', and number of tools 'n'
		cin >> a >> b >> n;
		long long x[n];
		// Read the increment values for each tool
		for (int i = 0; i < n; i++)
			cin >> x[i];

		// Initialize maximum_time with the initial timer value 'b'
		long long maximum_time = b;
		// Calculate the maximum time by adding the minimum of each tool's increment and (a-1)
		for (int i = 0; i < n; i++)
			maximum_time += min(x[i], a - 1);

		// Output the maximum time until the bomb explodes
		cout << maximum_time << endl;
	}
	return 0;
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n) = O(100)
