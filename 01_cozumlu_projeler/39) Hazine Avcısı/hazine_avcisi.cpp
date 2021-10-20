/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Bu soruda NxN tane odaya sahip bir sarayda hazine aramam�z istenmektedir.
 *			Bu saraydaki odalar�n hepsi x,y �eklinde numaraland�r�lm��t�r ve bu numaralar 1,1'den ba�layarak N,N'e kadar gitmektedir.
 *			Hazineyi bulabilmek i�in her odada bizi bir sonraki odaya g�t�recek bir ipucu bulunmaktad�r.
 *			Bu ipucu XY �eklinde iki basamakl� bir say�dan olu�makta ve buradaki X ve Y say�lar� X,Y �eklinde ele al�nd���nda bir sonraki odan�n numaras�n� vermektedir.
 *			Hazine oda numaras� ile i�erisinde bulunan ipucunun ayn� oldu�u odada bulunmaktad�r.
 *			Hazine oda numaras� ipuclar�ndan 1,1 nolu odadan ba�layarak hazineye g�t�ren yolu bulup ekrana yazd�ran program kodlar�n� yaz�n�z.
 */

#include <iostream>

#define MAX 10

using namespace std;

int main(){
	
	int saray[MAX][MAX], n, satir, sutun, ipucu, yeni_ipucu;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	cout << "Sayilari giriniz:";
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> saray[i][j];
		}
	}
	
	yeni_ipucu=11;
	
	cout << "Hazineye giden yol: ";
	do{
		ipucu=yeni_ipucu;
		cout << ipucu << " ";
		satir=ipucu/10;
		sutun=ipucu%10;
		yeni_ipucu=saray[satir-1][sutun-1];
	} while(ipucu!=yeni_ipucu);
	
	cout << endl;

	system("PAUSE");
	return 0;
}

