/*
 * Author: Hakan Ceran
 * Date: 12.09.2017
 * Content: 3*3'lük bir A matrisinin tersini hesaplayan program kodlarýný yazýnýz. Bu iþlemi yapabilmek için öncelikle determinat(|A|) hesaplamanýz gerekmektedir.
 */

#include <iostream>

void matris_gir(int matris[3][3]);
void matris_yaz(int matris[3][3]);
float determinant_hesapla(int matris[3][3]);
void matris_tersi(int matris[3][3]);

using namespace std;

int main(){
	
	int matris[3][3];
	
	matris_gir(matris);
	matris_yaz(matris);
	matris_tersi(matris);

	system("PAUSE");
	return 0;
}

void matris_gir(int matris[3][3]){
	cout << "3*3'luk bir matris giriniz: " << endl;
	
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			cin >> matris[i][j];
}

void matris_yaz(int matris[3][3]){
	// Matris yazýlýyor
	cout << endl << "Matris: " << endl;
	
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j)
			cout << matris[i][j] << "\t";
		cout << endl;
	}
}

float determinant_hesapla(int matris[3][3]){
	float determinant=0;
	
	for(int i=0; i<3; ++i)
		determinant+=(matris[0][i]*(matris[1][(i+1)%3]*matris[2][(i+2)%3]-matris[1][(i+2)%3]*matris[2][(i+1)%3]));
	
	return determinant;
}

void matris_tersi(int matris[3][3]){
	float determinant=determinant_hesapla(matris);
	if(determinant!=0){
		cout << endl << endl << "Matrisin tersi: " << endl << endl;
		
		for(int i=0; i<3; ++i){
			cout << endl;
		
		for(int j=0; j<3; ++j)
			cout << ((matris[(i+1)%3][(j+1)%3])*matris[(i+2)%3][(j+2)%3]-matris[(i+1)%3][(j+2)%3]*matris[(i+2)%3][(j+1)%3])/determinant << "\t";
		}
		cout << endl << endl;
	} else
		cout << "\nDeterminant 0 ise matrisin tersi hesaplanmaz!" << endl << endl;
}
