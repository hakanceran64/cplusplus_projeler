/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Bu soruda girdi olarak verilen bir matrisin transpozunun bulunmas� istenmektedir. Transpozu bulunacak matrsin sat�r ve s�tun say�s� kullan�c�dan istenecektir. 
 *			- Girilen matris maksimum 100 sat�r ve 100 s�tundan olu�mal�d�r.
 *			void yazdir(int mat[][MAX], int satir, int sutun)
 *			void transpoz(int mat[][MAX], int *satir, int *sutun)
 *			Yukar�daki fonksiyon prototiplerini kullan�n�z.
 */

#include <iostream>

#define MAX 100

using namespace std;

// Matris yazd�r
void yazdir(int mat[][MAX], int satir, int sutun){
	for(int i=0; i<satir; ++i){
		for(int j=0; j<sutun; ++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

// Matrisin transpozunu al
void transpoz(int mat[][MAX], int *satir, int *sutun){
	int tmp;
	tmp=*satir;
	*satir=*sutun;
	*sutun=tmp;
	
	for(int i=0; i<*satir; ++i){
		for(int j=0; j<*sutun; ++j){
			tmp=mat[i][j];
			mat[i][j]=mat[j][i];
			mat[j][i]=tmp;
		}
	}
}

int main(){
	
	int mat[MAX][MAX], satir, sutun;
	
	cout << "Satir ve sutun sayisini giriniz: ";
	cin >> satir >> sutun;
	
	cout << "Matrisi giriniz: " << endl;
	for(int i=0; i<satir; ++i){
		for(int j=0; j<sutun; ++j){
			cin >> mat[i][j];
		}
	}
	
	cout << "Girilen matris: " << endl;
	yazdir(mat,satir,sutun);
	
	transpoz(mat, &satir, &sutun);
	
	cout << "Girilen matrisin transpozu: " << endl;
	yazdir(mat, satir, sutun);

	system("PAUSE");
	return 0;
}

