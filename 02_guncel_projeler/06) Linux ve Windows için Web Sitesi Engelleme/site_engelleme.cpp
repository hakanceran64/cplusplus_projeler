/*
 * Author: Hakan Ceran
 * Date: 13.09.2017
 * Content: Kullanýcýnýn istediði bir web sitesine girisi engelleyen bir uygulama yazýnýz.
 *			Web sitesini engelleme þekli sisteme göre deðiþmektedir. Örneðin: Linux OS'da site engellemek isteniyorsa, /ets/host dosyasýna sitenin hostname'i(örneðin: www.deneme.com gibi) localhost (bilgisayarýn kendisi)'un IP numarasý ile yazmanýz istenmektedir.
 *			127.0.0.1 www.deneme.com
 *			Deðiþtirelecek doya windowsta ise C:/windwows/System32/drivers/etc/hosts 'dur.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(){
	int secim;
	string site;
	
	// Dosyay yazmak için ofstream kullanýlýr.
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

