/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Girdi olarak n(n<=100) say�s� boyutunda ekrana y�ld�z karakteriyle M harfi yazan bir program yaz�n�z.
 */

#include <iostream>

using namespace std;

int main(){
	
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	// En �st
	cout << "*";
	for(int i=0; i<n-2; ++i){
		cout << " ";
	}
	cout << "*" << endl;
	
	// �st Orta
	for(int j=0; j<n/2-1; ++j){
		cout << "*";
		for(int i=0; i<j; ++i){
			cout << " ";
		}
		cout << "*";
		for(int i=0; i<n-(j+2)*2; ++i){
			cout << " ";
		}
		cout << "*";
		for(int i=0; i<j; ++i){
			cout << " ";
		}
		cout << "*" << endl;
	}
	
	// Orta K�s�m
	cout << "*";
	for(int i=0; i<n/2-1; ++i){
		cout << " ";
	}
	cout << "*";
	for(int i=0; i<n/2-1; ++i){
		cout << " ";
	}
	cout << "*" << endl;
	
	// Alt K�s�m
	for(int j=0; j<n/2; ++j){
		cout << "*";	
		for(int i=0; i<n-2; ++i){
			cout << " ";
		}
		cout << "*" << endl;
	}

	system("PAUSE");
	return 0;
}

