/*
 * Author: Hakan Ceran
 * Date: 13.09.2017
 * Content: Bir basketbol tak�m�n�n ma� skoru kullan�c� taraf�ndan girilecektir. Soruda istenen ise rastgele olarak hangi sporcunun ka� say� atm�� olabilece�ini bulman�zd�r.
 *			Her oyuncu i�in bir say� �retmeniz gerekmektedir. �retilen bu say�lar toplam skora e�it olmal�d�r.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
	srand(time(NULL));
	int sayi;
	
	cout << "Firat universitesi kac sayi atmistir: ";
	cin >> sayi;
	
	int o1, o2, o3, o4, o5, o6;
	o1=rand()%sayi;
	o2=rand()%(sayi-o1);
	o3=rand()%(sayi-o1-o2);
	o4=rand()%(sayi-o1-o2-o3);
	o5=rand()%(sayi-o1-o2-o3-o4);
	o6=sayi-o1-o2-o3-o4-o5;
	
	if(o1>=0)
		cout << "o1: " << o1 << endl;
	if(o2>=0)
		cout << "o2: " << o2 << endl;
	if(o3>=0)
		cout << "o3: " << o3 << endl;
	if(o4>=0)
		cout << "o4: " << o4 << endl;
	if(o5>=0)
		cout << "o5: " << o5 << endl;
	cout << "o6: " << o6 << endl;
	

	system("PAUSE");
	return 0;
}

