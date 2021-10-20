/*
 * Author: Hakan Ceran
 * Date: 04.09.2017
 * Content: Girdi olarak verilen n(n<=100) say�s� boyutundaki ekrana y�ld�z karakterletiyle a�a��daki �ekli �izen program kodlay�n�z.
 *			      *
 *			     * *
 *			    *   *
 *			   *******
 *			  * *   * *
 *			 *   * *   *
 *			*************
 */

#include <iostream>

using namespace std;

int main(){
	
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	// Tepe Noktas�
	for(int i=0; i<n-1; ++i)
		cout << " ";
	cout << "*" << endl;
	for(int i=1; i<n/2; ++i){
		for(int j=i; j<n-1; ++j)
			cout << " ";
		cout << "*";
		for(int j=0; j<2*i-1; ++j)
			cout << " ";
		cout << "*" << endl;
	}
	for(int j=n/2; j<n-1; ++j)
		cout << " ";
	for(int j=0; j<n; ++j)
		cout << "*";
	cout << endl;
	for(int i=1; i<n/2; ++i){
		for(int j=i+n/2; j<n-1; ++j)
			cout << " ";
		cout << "*";
		for(int j=0; j<2*i-1; ++j)
			cout << " ";
		cout << "*";
		for(int j=0; j<n-2*(i+1); ++j)
			cout << " ";
		cout << "*";
		for(int j=0; j<2*i-1; ++j)
			cout << " ";
		cout << "*" << endl;
	}
	
	// B�y�k ��genin Taban�
	for(int i=0; i<2*n-1; ++i)
		cout << "*";
	cout << endl;

	system("PAUSE");
	return 0;
}

