/*
 * Author: Hakan Ceran
 * Date: 12.09.2017
 * Content: Bir üçgensel sayý, 1'den n'e kadar olan sayýlarýn toplamýdýr. Üçgensel sayý denmesinin sebebi ise toplarýn üçgen þeklinde dizildiðinde bu sayý deðerini vermesidir.
 *			Üçgensel sayý: (n^2+n)/2 formülü ile hesaplanýr.
 *			Bu kapsamda, kullanýcýnýn istediði üçgensel sayýyý bulan ve bu üçgensel sayýnýn yýldýzlardan oluþan üçgenini çizen programýn kodlarýný yazýnýz.
 */

#include <iostream>

using namespace std;

int main(){
	
	int i=0, bosluk=0, satir=0, k=0;
	int toplam;
	
	cout << "Satir degeri giriniz: ";
	cin >> satir;
	
	// Yýldýzlar ile üçgen çizdirme
	for(i=1; i<=satir; ++i){
		for(bosluk=1; bosluk<=satir-i; ++bosluk)
			cout << "  ";
		while(k!=2*i-1){
			cout << "* ";
			++k;
		}
		k=0;
		cout << endl;
	}
	
	// Üçgensel sayýnýn hesaplanmasý
	
	toplam=satir*(satir+1)/2;
	
	cout << "T_" << satir << "=" << toplam << endl;

	system("PAUSE");
	return 0;
}

