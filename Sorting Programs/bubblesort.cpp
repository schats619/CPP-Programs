#include<iostream>
#include<conio.h>
using namespace std;

int main(){

	int numb[7];
	int i, j;
	
	for(i=0;i<=6;i++){

		cout<<"Enter the numbers"<<endl;
		cin>>numb[i];
	}
	
	for(i=0;i<=5;j++){

			for(j=j+1;j<=6;j++){

		int temp;
		if(numb[i]> numb[j]){

		temp = numb[i];
		numb[i]=numb[j];
		numb[j]=temp;
	}
	}
}
	for(i=0;i<=6;i++){
		cout<<numb[i]<<endl;
	}
		getch();
		return 0;
}
