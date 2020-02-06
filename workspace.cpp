#include <iostream>

using namespace std;

int main(){
    int i = 3, j = 5, k;
    int * p = &i, * q = &j;
    int * r;
    r = &k;
    *r = *p * *q;

	cout << i << " " << j << " " << k << " " << endl;
	cout << *p << " " << *q << " " << *r << " " << endl;
	cout << &i << " " << &j << " " << &k << " " << endl;
	cout << p << " " << q << " " << r << " " << endl;

/*
*x = contents of what x points to
&x = address of x
x = contents of x. if x is a pointer, gives address of what it points to
 */

    return 0;
}