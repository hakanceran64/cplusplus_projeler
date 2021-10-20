/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Girdi olarak n(n<=100) sayısı boyutunda ekrana yıldız karakteriyle N harfi yazan bir program yazınız.
 */

#include <iostream>

using namespace std;

int main(){
	
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	cout << "*";
	for(int i=0; i<n-2; ++i){
		cout << " ";
	}
	cout << "*" << endl;
	
	for(int i=0; i<n-2; ++i){
		cout << "*";
		for(int j=0; j<i; ++j){
			cout << " ";
		}
		cout << "*";
		for(int j=0; j<n-3-i; ++j){
			cout << " ";
		}
		cout << "*" << endl;
	}
	
	cout << "*";
	for(int i=0; i<n-2; ++i){
		cout << " ";
	}
	cout << "*" << endl;

	system("PAUSE");
	return 0;
}

