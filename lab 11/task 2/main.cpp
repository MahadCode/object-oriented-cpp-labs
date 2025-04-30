#include<iostream>
using namespace std;

int maxProduct(int arr[], int n, int size) {
	if ((n) == (size-2)) {
		return arr[n] * arr[n+1];
	}

	int maximum=INT_MIN;
	for (int i = n+1; i < size; i++) {
		    int curr = arr[n] * arr[i];
			maximum = max(maximum, curr);
	}
	int second = maxProduct(arr, n + 1, size);
	maximum = max(second, maximum);
	return maximum;
}

int main() {
	int arr[] = {1,3,5,2,9};
	int n = 5;
	int c = maxProduct(arr, 0,5);
	cout << c << endl;
}