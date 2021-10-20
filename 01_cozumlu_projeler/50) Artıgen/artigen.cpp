/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Girdi olarak n(n<=100) sayýsý boyutunda ekrana yýldýz karakteriyle artýgen þekli çizen bir program yazýnýz.
 */

#include <iostream>

using namespace std;

int main(){
	
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	for(int i=0; i<n-1; ++i)
		cout << " ";
	for(int i=0; i<n; ++i)
		cout << "*";
	cout << endl;
	for(int j=0; j<n-2; ++j){
		for(int i=j; i<n-2; ++i)
			cout << " ";
		cout << "*";
		for(int i=0; i<n/2+j; ++i)
			cout << " ";
		cout << "*";
		for(int i=0; i<n/2+j; ++i)
			cout << " ";
		cout << "*" << endl;
	}
	for(int i=0; i<3*n-2; ++i)
		cout << "*";
	cout << endl;
	for(int j=n-3; j>=0; --j){
		for(int i=j; i<n-2; ++i)
			cout << " ";
		cout << "*";
		for(int i=0; i<n/2+j; ++i)
			cout << " ";
		cout << "*";
		for(int i=0; i<n/2+j; ++i)
			cout << " ";
		cout << "*" << endl;
	}
	for(int i=0; i<n-1; ++i)
		cout << " ";
	for(int i=0; i<n; ++i)
		cout << "*";
	cout << endl;

	system("PAUSE");
	return 0;
}

