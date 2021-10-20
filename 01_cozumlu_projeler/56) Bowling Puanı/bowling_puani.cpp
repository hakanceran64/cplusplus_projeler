/*
 * Author: Hakan Ceran
 * Date: 02.09.2017
 * Content: Bu soruda bir bowling maçında bir oyuncunun yıktığı kula sayılarından, o oyuncunun puanını hesaplayan bir program yazınız.
 *			Bowling'de bir oyuncuya bir maçta 10 frame hakkı verilir. Her frame 10 kukadan oluşur ve oyuncunun her frame için 2 atış hakkı vardır.
 *			Oyuncunun ilk atış hakkında bütün kukaları devirmesine strike, iki atışta toplamda bütün kukaları devirmesine ise spare adı verilir.
 *			10. yani son framede oyuncu strike yaparsa ekstra iki atış hakkı daha verilir, spare yaparsa bir atış hakkı daha verilir.
 *			Puan Hesabı: Oyuncu her strike yaptığında strike'den hemen sonraki 2 atışında aldığı kadar puan daha alır, spare yaptığında ise spare'den bir sonraki atışında aldığı kadar puan daha alır.
 *						 Diğer durumlarda ise sadece yıktığı kuka sayısı kadar puan alır.
 */

#include <iostream>

using namespace std;

int main(){
	
	int atis_1, atis_2, atis_sayisi=0, puan=0;
	int kuka_sayilari[22];
	
	// Atışları Al
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

