/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: Bütün hayvanlarýn duyma frekansý farklýdýr.
 *			Bu projede istenen, bu farklýlýðý kullanarak rahatsýz edici bir sesle hayvanlarý etraftan uzaklaþtýran bir uygulama yazýlmasýdýr.
 *			Bu iþlem bilgisayarýn Beep (frekans, milisaniye) fonksiyonu kullanýlarak yapýlabilir.
 *			Aþaðýda bazý hayvanlarýn duyabilecekleri frekans aralýklarý verilmiþtir.
 *				Ýnsan: 20 Hz - 20 Khz
 *				Kedi: 100 Hz - 60 Khz
 *				Fare: 1 Khz - 100 Khz
 *				Köpek: 50 Khz'e kadar
 *				Fil: 1 Hz - 20 Khz
 *				Kuþ: 100 Hz - 29.000 Hz
 *				Balýk: 200 Hz - 800 Hz
 *				Sivrisinek: 1200 Hz - 2000 Hz
 *
 *			NOT: Bu uygulamada sadece bir menu ve seçimin ardýndan bilgisayar tarafýndan ses çýkarýlmasý saðladýðýndan ekran görünümü verilmesine ihtiyaç duyulmamýþtýr.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <iomanip>

using namespace std; // std::

/*
 *
 * Ýnsan: 20 Hz - 20 Khz
 * Kedi: 100 Hz - 60 Khz
 * Fare: 1 Khz - 100 Khz
 * Köpek: 50 Khz'e kadar
 * Fil: 1 Hz - 20 Khz
 * Kuþ: 100 Hz - 29.000 Hz
 * Balýk: 200 Hz - 800 Hz
 * Sivrisinek: 1200 Hz - 2000 Hz
 *
 */

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	system("cls");
	
	int secim;
	
	cout << "*************************************" << endl;
	cout << "* 1) Test(insanýn duyabileceði ses) *" << endl;
	cout << "* 2) Sinek Savar                    *" << endl;
	cout << "* 3) Kedi Savar                     *" << endl;
	cout << "* 4) Köpek Savar                    *" << endl;
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
			
			cout << "Bir frekans aralýðý ve süre giriniz: ";
			cin >> frekans >> sure;
			
			Beep(frekans,sure);
			break;
		default:
			cout << "Seçiminiz yanlýþtýr." << endl;
	}

	return main();
}


