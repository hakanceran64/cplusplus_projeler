/*
 * Author: Hakan Ceran
 * Date: 19.09.2017
 * Content: E�er bir inek 2 ya��ndan her y�l bir dana do�uruyor ise x y�l sonra (ineklerden hi� biri �lmezse) toplam ka� inek olur problemini hesaplayan program kodlar�n� yaz�n�z.
 *			Bu probleme Dudeney's Cows denir.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi

using namespace std; // std::

int fib(int);

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	int n;
	
	cout << "Ka� y�l sonra ne kadar ine�iniz olaca��n� hesaplay�n�z: ";
	cin >> n;
	
	for(int i=0; i<n; i++){
		cout << i+1 << ". y�l toplam inek say�s�: " << fib(i) << endl;
	}

	system("PAUSE");
	return 0;
}

// Dudeney'in inekleri problemi fibonacci serisi ile ��z�lebilir. Bu �rnekte recursive (�zyinelemeli) fonksiyon kullan�lm��t�r. �stenirse recursive yap� kullan�lmadan yap�labilir.
int fib(int n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

