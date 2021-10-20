/*
 * Author: Hakan Ceran
 * Date: 12.09.2017
 * Content: Kullanýcý tarafýndan katsayýlarý girilen 2. dereceden bir fonksiyonun kökler toplamý, kökler çarpýmý ve köklerini bulan kodu yazýnýz.
 *			Örneðin: ax2 + bx + c denklemi ikinci dereceden bir denklemdir.
 */

#include <iostream>
#include <cmath>

using namespace std;

void kokleri_hesapla(double, double, double);

int main(){
	
	double a, b, c, d;
	char devam;
	
	do{
		kokleri_hesapla(a,b,c);
		
		cout << "\nDevam etmek istiyor musunuz? (e/h):";
		cin >> devam;
		
	}while(devam=='e');

	system("PAUSE");
	return 0;
}

void kokleri_hesapla(double a, double b, double c){
	double delta, x1, x2, x1re, x1sa, x2sa, x2re;
	
	cout << "Orn: ax2+bx+c=0\n";
	cin >> a >> b >> c;
	
	delta=(b*b)-(4*a*c);
	
	cout << "Kokler toplami= " << -b/a << endl;
	cout << "Kokler carpimi= " << c/a << endl;
	
	if(delta<0){
		cout << "Reel kok yoktur.\n";
		delta=fabs(delta);
		x1re=(-b/a);
		x1sa=(sqrt(delta)/(2*a));
		x2re=(-b/a);
		x2sa=(sqrt(delta)/(2*a));
		cout << "x1= " << x1re << "+i*" << x1sa << endl;
		cout << "x2= " << x2re << "-i*" << x2sa << endl;
	} else if(delta==0){
		cout << "Simetrik iki kok vardir.\n";
		x1=(-b)/(2*a);
		cout << "x1= " << x1 << " x2= " << x2 << endl;
	} else if(delta>0){
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);
		
		cout << "Ýki reel kok vardir.\n";
		cout << "x1= " << x1 << " x2= " << x2 << endl;
	}
}
