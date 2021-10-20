/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Fibonacci sayýlarýný bulan bir program yazýnýz.
 */

#include <iostream>

using namespace std;

int fibonacci(int n); // Fonksiyon Prototipi (Forward decleration)

int main(){
	
	int n;
	
	cout << "Fibonacci icin sayi giriniz: ";
	cin >> n;
	
	cout << "Sayinin fibonaccisi: " << fibonacci(n) << endl;
	
	system("PAUSE");
	return 0;
}

int fibonacci(int n){
	if(n<0)
		return -1;
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	
	return fibonacci(n-1)+fibonacci(n-2);
}
