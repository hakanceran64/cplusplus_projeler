/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Girdi olarak n(n<=100) sayýsý boyutunda ekrana yýldýz karakteriyle X harfi yazan bir program yazýnýz.
 */

#include <iostream>

using namespace std;

int main(){
	
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	for(int i=0; i<n/2; ++i){
		for(int j=0; j<i; ++j)
			cout << " ";
		cout << "*";
		for(int j=0; j<n-(i+1)*2; ++j)
			cout << " ";
		cout << "*" << endl;
	}
	for(int i=0; i<n/2; ++i)
		cout << " ";
	
	// Ortadaki tek nokta
	cout << "*" << endl;
	
	for(int i=n/2-1; i>=0; --i){
		for(int j=0; j<i; ++j)
			cout << " ";
		cout << "*";
		for(int j=0; j<n-(i+1)*2; ++j)
			cout << " ";
		cout << "*" << endl;
	}
	
	system("PAUSE");
	return 0;
}

