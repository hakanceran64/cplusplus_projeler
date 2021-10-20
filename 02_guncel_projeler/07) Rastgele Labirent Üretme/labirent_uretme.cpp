/*
 * Author: Hakan Ceran
 * Date: 13.09.2017
 * Content: 20x70 boyutunda #, +, 0'lardan olu�an rastgele bir labirent �retiniz. D�� duvarlar # olsun i�erisi ise + ve 0'lardan olu�sun
 *			#####
 *			#++0#
 *			#0++#
 *			#000#
 *			#####
 *
 *			Yukar�daki tabloda g�r�ld��� gibi bir matris �retilen matrisi bir dosyaya yazd�r�r�z. '+' ve '0'�n labirentte bulunma olas�l��� e�ittir.
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
			if(i==0 || j==0 || i==19 || j==69){ // D�� duvarlar
				myfile << "#";
			} else if(r==0){ // �� duvarlar
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

