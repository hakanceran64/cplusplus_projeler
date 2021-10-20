/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: �ki double say�y� (a ve b) b�len (a/b) bit uygulama yaz�n�z.
 *			Uygulama kodlar�n� yazarken muhtemel 0'a b�lme hatas�ndan sak�nacak �ekilde kodlar� organize ediniz.
 *			Hata kontrol�n kullan�lan try-catch yap�s� a�a��da verilmi�tir. Bu yap�dan faydalanarak istenen i�lemi yapmak m�mk�nd�r.
 *				try{
 *					cout << bol(a,b) << endl;
 *				}
 *				catch(const char* msg){
 *					cerr << msg << endl;
 *				}
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi

using namespace std; // std::

double bol(double a, double b);

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	double a, b;
	
	cout << "Say�lar� giriniz: ";
	cin >> a >> b;
	
	// try i�erisindeki i�lem yap�lmaz ise program catch blo�una y�nlenir ve cacth blo�undaki kod par�as� �al���r.
	try{
		cout << bol(a,b) << endl;
	}
	catch(const char* msg){
		cerr << msg << endl;
	}

	system("PAUSE");
	return 0;
}

double bol(double a, double b){
	// Hata throw ile f�rlat�l�r
	if(b==0){
		throw "S�f�r'a b�lme hatas�"; // Mesaj� f�rlat
	}
	
	return a/b;
}

