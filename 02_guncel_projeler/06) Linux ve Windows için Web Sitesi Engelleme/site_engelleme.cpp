/*
 * Author: Hakan Ceran
 * Date: 13.09.2017
 * Content: Kullan�c�n�n istedi�i bir web sitesine girisi engelleyen bir uygulama yaz�n�z.
 *			Web sitesini engelleme �ekli sisteme g�re de�i�mektedir. �rne�in: Linux OS'da site engellemek isteniyorsa, /ets/host dosyas�na sitenin hostname'i(�rne�in: www.deneme.com gibi) localhost (bilgisayar�n kendisi)'un IP numaras� ile yazman�z istenmektedir.
 *			127.0.0.1 www.deneme.com
 *			De�i�tirelecek doya windowsta ise C:/windwows/System32/drivers/etc/hosts 'dur.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(){
	int secim;
	string site;
	
	// Dosyay yazmak i�in ofstream kullan�l�r.
	ofstream out;
	basla:
	
	cout << "Isletim sisteminizi seciniz: " << endl;
	cout << "1: Windows" << endl
		 << "2: Linux" << endl;
	cin >> secim;
	
	switch(secim){
		case 1:
			cout << "Engellenecek siteyi giriniz: ";
			cin >> site;
			out.open("C:/Windows/System32/drivers/etc/hosts",ios::app);
			if(!out)
				cout << "Yonetici olarak calistirmayi deneyiniz." << endl;
			else{
				out << "127.0.0.1" << "\t" << site << endl;
				cout << site << "\tEngellendi" << endl;
			}
			break;
		case 2:
			cout << "Engellenecek siteyi giriniz: ";
			cin >> site;
			out.open("/etc/hosts",ios::app);
			if(!out)
				cout << "Yonetici olarak calistirmayi deneyiniz." << endl;
			else{
				out << "127.0.0.1" << "\t" << site << endl;
				cout << site << "\tEngellendi" << endl;
			}
			break;
		default:
			cout << "Yanlis secim yaptiniz." << endl;
			goto basla;
			break;
	}

	system("PAUSE");
	return 0;
}

