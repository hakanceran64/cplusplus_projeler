/*
 * Author: Hakan Ceran
 * Date: 12.09.2017
 * Content: Bir ��gensel say�, 1'den n'e kadar olan say�lar�n toplam�d�r. ��gensel say� denmesinin sebebi ise toplar�n ��gen �eklinde dizildi�inde bu say� de�erini vermesidir.
 *			��gensel say�: (n^2+n)/2 form�l� ile hesaplan�r.
 *			Bu kapsamda, kullan�c�n�n istedi�i ��gensel say�y� bulan ve bu ��gensel say�n�n y�ld�zlardan olu�an ��genini �izen program�n kodlar�n� yaz�n�z.
 */

#include <iostream>

using namespace std;

int main(){
	
	int i=0, bosluk=0, satir=0, k=0;
	int toplam;
	
	cout << "Satir degeri giriniz: ";
	cin >> satir;
	
	// Y�ld�zlar ile ��gen �izdirme
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
	
	// ��gensel say�n�n hesaplanmas�
	
	toplam=satir*(satir+1)/2;
	
	cout << "T_" << satir << "=" << toplam << endl;

	system("PAUSE");
	return 0;
}

