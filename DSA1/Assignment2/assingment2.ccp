#include <iostream>
using namespace std;
void mystery4(int a[], int n);
int main(void) {
	int a[] = { 9,10,7,8,6,4,5,2,3,1 };
	mystery4(a, 10);
	for (int j = 0; j < 10; j++) {
		cout << a[j] << endl;
	}

}
void mystery4(int a[], int n) {
	int temp, i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			} // end if 
		} // end 2nd for
	} // end 1st for
} // end function

