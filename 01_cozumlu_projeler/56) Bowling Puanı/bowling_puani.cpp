/*
 * Author: Hakan Ceran
 * Date: 02.09.2017
 * Content: Bu soruda bir bowling ma��nda bir oyuncunun y�kt��� kula say�lar�ndan, o oyuncunun puan�n� hesaplayan bir program yaz�n�z.
 *			Bowling'de bir oyuncuya bir ma�ta 10 frame hakk� verilir. Her frame 10 kukadan olu�ur ve oyuncunun her frame i�in 2 at�� hakk� vard�r.
 *			Oyuncunun ilk at�� hakk�nda b�t�n kukalar� devirmesine strike, iki at��ta toplamda b�t�n kukalar� devirmesine ise spare ad� verilir.
 *			10. yani son framede oyuncu strike yaparsa ekstra iki at�� hakk� daha verilir, spare yaparsa bir at�� hakk� daha verilir.
 *			Puan Hesab�: Oyuncu her strike yapt���nda strike'den hemen sonraki 2 at���nda ald��� kadar puan daha al�r, spare yapt���nda ise spare'den bir sonraki at���nda ald��� kadar puan daha al�r.
 *						 Di�er durumlarda ise sadece y�kt��� kuka say�s� kadar puan al�r.
 */

#include <iostream>

using namespace std;

int main(){
	
	int atis_1, atis_2, atis_sayisi=0, puan=0;
	int kuka_sayilari[22];
	
	// At��lar� Al
	cout << "Atislari giriniz: ";
	for(int i=0; i<10; ++i){
		cin >> atis_1;
		kuka_sayilari[atis_sayisi++]=atis_1;
		if(atis_1!=10){
			cin >> atis_2;
			kuka_sayilari[atis_sayisi++]=atis_2;
		}
		if(atis_1==10 && i==9){
			cin >> atis_1;
			kuka_sayilari[atis_sayisi++]=atis_1;
			cin >> atis_2;
			kuka_sayilari[atis_sayisi++]=atis_2;
		} else if(atis_1+atis_2==10 && i==9){
			cin >> atis_1;
			kuka_sayilari[atis_sayisi++]=atis_1;
		}
	}
	
	// Puan Hesapla
	bool strike, spare;
	for(int i=0, j=0; i<10; ++i){
		strike=false;
		spare=false;
		if(kuka_sayilari[j]==10){
			puan+=kuka_sayilari[j]+kuka_sayilari[j+1]+kuka_sayilari[j+2];
			j+=1;
			strike=true;
		} else if(kuka_sayilari[j]+kuka_sayilari[j+1]==10){
			puan+=kuka_sayilari[j]+kuka_sayilari[j+1]+kuka_sayilari[j+2];
			j+=2;
			spare=true;
		} else{
			puan+=kuka_sayilari[j]+kuka_sayilari[j+1];
			j+=2;
		}
	}
	
	cout << puan << endl;

	system("PAUSE");
	return 0;
}

