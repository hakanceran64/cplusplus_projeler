/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: B�t�n hayvanlar�n duyma frekans� farkl�d�r.
 *			Bu projede istenen, bu farkl�l��� kullanarak rahats�z edici bir sesle hayvanlar� etraftan uzakla�t�ran bir uygulama yaz�lmas�d�r.
 *			Bu i�lem bilgisayar�n Beep (frekans, milisaniye) fonksiyonu kullan�larak yap�labilir.
 *			A�a��da baz� hayvanlar�n duyabilecekleri frekans aral�klar� verilmi�tir.
 *				�nsan: 20 Hz - 20 Khz
 *				Kedi: 100 Hz - 60 Khz
 *				Fare: 1 Khz - 100 Khz
 *				K�pek: 50 Khz'e kadar
 *				Fil: 1 Hz - 20 Khz
 *				Ku�: 100 Hz - 29.000 Hz
 *				Bal�k: 200 Hz - 800 Hz
 *				Sivrisinek: 1200 Hz - 2000 Hz
 *
 *			NOT: Bu uygulamada sadece bir menu ve se�imin ard�ndan bilgisayar taraf�ndan ses ��kar�lmas� sa�lad���ndan ekran g�r�n�m� verilmesine ihtiya� duyulmam��t�r.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <iomanip>

using namespace std; // std::

/*
 *
 * �nsan: 20 Hz - 20 Khz
 * Kedi: 100 Hz - 60 Khz
 * Fare: 1 Khz - 100 Khz
 * K�pek: 50 Khz'e kadar
 * Fil: 1 Hz - 20 Khz
 * Ku�: 100 Hz - 29.000 Hz
 * Bal�k: 200 Hz - 800 Hz
 * Sivrisinek: 1200 Hz - 2000 Hz
 *
 */

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	system("cls");
	
	int secim;
	
	cout << "*************************************" << endl;
	cout << "* 1) Test(insan�n duyabilece�i ses) *" << endl;
	cout << "* 2) Sinek Savar                    *" << endl;
	cout << "* 3) Kedi Savar                     *" << endl;
	cout << "* 4) K�pek Savar                    *" << endl;
	cout << "* 5) Manuel                         *" << endl;
	cout << "*************************************" << endl;
	cin >> secim;
	
	switch(secim){
		case 1:
			Beep(10000,10000);
			break;
		case 2:
			Beep(1500,10000);
			break;
		case 3:
			Beep(50000,10000);
			break;
		case 4:
			Beep(30000,10000);
			break;
		case 5:
			int sure, frekans;
			
			cout << "Bir frekans aral��� ve s�re giriniz: ";
			cin >> frekans >> sure;
			
			Beep(frekans,sure);
			break;
		default:
			cout << "Se�iminiz yanl��t�r." << endl;
	}

	return main();
}


