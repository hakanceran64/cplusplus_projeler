/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Girdi olarak n(n<=100) say�s� boyutunda ekrana y�ld�z karakteriyle R harfi yazan bir program yaz�n�z.
 */

#include <iostream>

using namespace std;

int main(){
	
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	// �st Kare
	for(int i=0; i<n/2+1; ++i)
		cout << "*";
	cout << endl;
	for(int i=0; i<n/2-1; ++i){
		cout << "*";
		for(int j=0; j<n/2-1; ++j)
			cout << " ";
		cout << "*" << endl;
	}
	for(int i=0; i<n/2+1; ++i)
		cout << "*";
	cout << endl;
	
	// Alt �izgiler
	for(int i=0; i<n/2; ++i){
		cout << "*";
		for(int j=0; j<i; ++j)
			cout << " ";
		cout << "*" << endl;
	}

	system("PAUSE");
	return 0;
}

