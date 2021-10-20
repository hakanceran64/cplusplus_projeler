/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Bu soruda NxN tane odaya sahip bir sarayda hazine aramamýz istenmektedir.
 *			Bu saraydaki odalarýn hepsi x,y þeklinde numaralandýrýlmýþtýr ve bu numaralar 1,1'den baþlayarak N,N'e kadar gitmektedir.
 *			Hazineyi bulabilmek için her odada bizi bir sonraki odaya götürecek bir ipucu bulunmaktadýr.
 *			Bu ipucu XY þeklinde iki basamaklý bir sayýdan oluþmakta ve buradaki X ve Y sayýlarý X,Y þeklinde ele alýndýðýnda bir sonraki odanýn numarasýný vermektedir.
 *			Hazine oda numarasý ile içerisinde bulunan ipucunun ayný olduðu odada bulunmaktadýr.
 *			Hazine oda numarasý ipuclarýndan 1,1 nolu odadan baþlayarak hazineye götüren yolu bulup ekrana yazdýran program kodlarýný yazýnýz.
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

