#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		int n;
		cin >> n; // Read the length of the permutation
		vector<int> a(n);
		for (int i = 0; i < n; i++) // Read the permutation elements
			cin >> a[i];
		
		// Initialize k as the absolute difference between the first element and its sorted position
		int k = abs(a[0] - 1);
		for (int i = 1; i < n; i++) // Iterate over the permutation
		{
			// Update k to be the gcd of current k and the absolute difference between
			// the current element and its sorted position
			k = gcd(k, abs(a[i] - (i + 1)));
		}
		// Output the maximum k that can be used to sort the permutation
		cout << k << endl;
	}
	return 0;
}

// Time Complexity (TC): O(nlogn) = O(10^5*20) = O(2*10^6)
// Space Complexity (SC): O(n) = O(10^5)
