/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: B serisi say�lar� 0 ve 1'den ba�layarak bir sonraki say� kendinden �nce iki B serisi �ift say�s�n�n toplam�na e�it olan say� dizisidir. B serisinde tek say�lar�n ve eksi say�lar�n de�eri -1 dir.
 */

#include <iostream>

using namespace std;

int b_serisi(int n);

int main(){
	
	int n;
	
	cout << "B serisi i�in sayi giriniz: ";
	cin >> n;
	
	cout << "Sayinin B serisi degeri: " << b_serisi(n) << endl;

	system("PAUSE");
	return 0;
}

int b_serisi(int n){
	if(n<0 || n%2==1)
		return -1;
	if(n==0)
		return 0;
	if(n==2)
		return 1;
	
	return b_serisi(n-2)+b_serisi(n-4);
}
