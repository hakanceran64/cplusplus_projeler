/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: Ýki double sayýyý (a ve b) bölen (a/b) bit uygulama yazýnýz.
 *			Uygulama kodlarýný yazarken muhtemel 0'a bölme hatasýndan sakýnacak þekilde kodlarý organize ediniz.
 *			Hata kontrolün kullanýlan try-catch yapýsý aþaðýda verilmiþtir. Bu yapýdan faydalanarak istenen iþlemi yapmak mümkündür.
 *				try{
 *					cout << bol(a,b) << endl;
 *				}
 *				catch(const char* msg){
 *					cerr << msg << endl;
 *				}
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi

using namespace std; // std::

double bol(double a, double b);

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	double a, b;
	
	cout << "Sayýlarý giriniz: ";
	cin >> a >> b;
	
	// try içerisindeki iþlem yapýlmaz ise program catch bloðuna yönlenir ve cacth bloðundaki kod parçasý çalýþýr.
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
	// Hata throw ile fýrlatýlýr
	if(b==0){
		throw "Sýfýr'a bölme hatasý"; // Mesajý fýrlat
	}
	
	return a/b;
}

