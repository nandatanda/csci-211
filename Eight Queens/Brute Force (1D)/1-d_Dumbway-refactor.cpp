//Saul E. McCoy 
//23985411

#include <iostream>
using namespace std;

bool ok ( int q[], int c){	// Returns true if col is vaild 
	for ( int i = 0; i < c; i++){	// going the the specific col 
		if ( q[c] == q[i] || (c - i) == abs( q[c] - q[i]))	//doing row and diag testing 
			return false; 
	}
	return true;
}

void print ( int q[]){
	for ( int i = 0; i < 8; i++){
		for ( int j = 0; j < 8; j++){
			if ( q[j] == i)
				cout << "1  ";
			else
				cout << "0  ";
		}
		cout << endl;
	}
}

int main(){
	int q[8],sol,c=0;
	//Starting from the i7 going from 0-7 to see if the number is valid or not
	for ( int i0=0; i0<7; i0++) 
		for ( int i1=0;i1<7;i1++)
			for ( int i2=0;i2<7;i2++)
				for ( int i3=0;i3<7;i3++)
					for (int i4=0;i4<7;i4++)
						for (int i5=0;i5<7;i5++)
							for ( int i6=0;i6<7;i6++)
								for ( int i7=0;i7<7;i7++)//starting from here want to see if there's a conflict
								{	
									q[0]=i0;
									q[1]=i1;
									q[2]=i2;
									q[3]=i3;
									q[4]=i4;
									q[5]=i5;
									q[6]=i6;
									q[7]=i7;

									if (ok(q, c)){
										cout << "Solution # "<< ++sol<< ":"<<endl;
										print(q);
										cout << endl;
									}
								}
	return 0;
}
