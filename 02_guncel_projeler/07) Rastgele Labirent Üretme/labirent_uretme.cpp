/*
 * Author: Hakan Ceran
 * Date: 13.09.2017
 * Content: 20x70 boyutunda #, +, 0'lardan oluþan rastgele bir labirent üretiniz. Dýþ duvarlar # olsun içerisi ise + ve 0'lardan oluþsun
 *			#####
 *			#++0#
 *			#0++#
 *			#000#
 *			#####
 *
 *			Yukarýdaki tabloda görüldüðü gibi bir matris üretilen matrisi bir dosyaya yazdýrýrýz. '+' ve '0'ýn labirentte bulunma olasýlýðý eþittir.
 */

#include <iostream>
#include <stdlib.h> // srand rand
#include <time.h>
#include <fstream>

using namespace std;

int main(){
	
	srand(time(NULL));
	
	int r;
	
	ofstream myfile;
	myfile.open("labirent.txt");
	
	for(int i=0; i<20; i++){
		for(int j=0; j<70; j++){
			r=rand()%2;
			if(i==0 || j==0 || i==19 || j==69){ // Dýþ duvarlar
				myfile << "#";
			} else if(r==0){ // Ýç duvarlar
				myfile << "0";
			} else{
				myfile << "+"; // Yollar
			}
		}
		myfile << endl;
	}
	
	cout << "Labirent dosyaya yazdirildi.\n";
	myfile.close();

	system("PAUSE");
	return 0;
}

