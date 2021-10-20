/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: a/b format�nda girilen kesirli bir say�n�n en sade halini bulan bir fonksiyon yaz�n�z.
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
	// K���k olan� bul
	int kucuk=*pay;
	
	if(*payda<kucuk)
		kucuk=*payda;
	
	for(int i=2; i<kucuk; ++i){
		// i ve pay ve payday� tam b�ld��� s�rece sadele�ir
		while(*pay%i==0 && *payda%i==0){
			*pay/=i;
			*payda/=i;
		}
		// i pay veya paydadan b�y�kse geri kalan�n� kontrol etmeye gerek yok.
		if(i>*pay || i>*payda)
			break;
	}
}
