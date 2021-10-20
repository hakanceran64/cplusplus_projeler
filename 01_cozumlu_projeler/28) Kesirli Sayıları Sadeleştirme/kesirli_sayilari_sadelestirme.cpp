/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: a/b formatýnda girilen kesirli bir sayýnýn en sade halini bulan bir fonksiyon yazýnýz.
 */

#include <iostream>

using namespace std;

void sadelestir(int *pay, int *payda);

int main(){
	
	int a, b;
	char x;
	
	cin >> a >> x >> b;
	
	sadelestir(&a,&b);
	
	cout << "En sade hali: " << a << " / " << b << endl;

	system("PAUSE");
	return 0;
}

void sadelestir(int *pay, int *payda){
	// Küçük olaný bul
	int kucuk=*pay;
	
	if(*payda<kucuk)
		kucuk=*payda;
	
	for(int i=2; i<kucuk; ++i){
		// i ve pay ve paydayý tam böldüðü sürece sadeleþir
		while(*pay%i==0 && *payda%i==0){
			*pay/=i;
			*payda/=i;
		}
		// i pay veya paydadan büyükse geri kalanýný kontrol etmeye gerek yok.
		if(i>*pay || i>*payda)
			break;
	}
}
