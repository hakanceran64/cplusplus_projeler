/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: A Serisi sayıları 2 ve 3'den başlayarak bir sonraki sayı kendinden önce iki a_serisi sayısının çarpımına eşit olann sayı dizisidir.
 */

#include <iostream>

using namespace std;

int a_serisi(int n);

int main(){
	
	int n;
	
	cout << "A serisi icin bir sayi giriniz: ";
	cin >> n;
	
	cout << "Sayinin a serisi degeri: " << a_serisi(n) << endl;

	system("PAUSE");
	return 0;
}

int a_serisi(int n){
	if(n<0)
		return -1;
	if(n==0)
		return 2;
	if(n==1)
		return 3;
	
	return a_serisi(n-1)*a_serisi(n-2);
}
