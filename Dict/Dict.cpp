/*
 * Dict.cpp
 *
 *  Created on: 26 февр. 2019 г.
 *      Author: nikit
 */

#include <iostream>
#include <string>
#include "OrtList.h"
using namespace std;

inline ostream& operator <<(ostream& os, OList x);


int main(){
	OList list;


	int c=-1;
	cout<<"Press 1 to add an english word in the dictionary\n"<<
					"Press 2 to add a russian word in the dictionary\n"<<
					"Press 3 to translate a word\n"<<
					"Press 4 to delete an english word in the dictionary\n"<<
					"Press 5 to delete a russian word in the dictionary\n"<<
					"Press 0 to exit from program:\n";
	while(true){


		cin>>c;
		if(c==1){
			cout<<"Enter an english word:\n";
			string EWord;

			cin>>EWord;
			if(list.AddEnglishWord(EWord))
				cout<<"Reading successful\n";
			else
				cout<<"reading failed \n";
		}
		else if(c==2){
			cout<<"Enter an english word and then a russian word:\n";
			string EWord;
			string RWord;
			cin>>EWord>>RWord;
			if(list.AddTranslate(EWord,RWord))
				cout<<"Reading successful\n";
			else
				cout<<"Reading failed\n";
		}
		else if(c==3){
			cout<<"Enter an word to translate: ";
			string EWord;
			cin>>EWord;
			cout<<list.Translate(EWord);
		}
		else if(c==4){
			cout<<"Enter an word you want to delete:\n";
			string EWord;
			cin>>EWord;
			list.DeleteEnglishWord(EWord);
		}
		else if(c==5){
			cout<<"Enter an English and then a Russian word you want to delete:\n";
			string EWord;
			string RWord;
			cin>>EWord>>RWord;
			list.DeleteTranlate(EWord,RWord);
		}
		else if(c==6){
			cout<<list;
		}
		else if(c==0)
			break;
		else{
			cout<<"Incorrect symbol, try again\n";
		}
		cout<<endl;
	}
}

inline ostream& operator <<(ostream& os, OList x){
	if(x.isEmpty()){
		os<<"list is empty";
	}
	else{
		x.GoHead();
		do{
			os<<x.GetKey()<<":";
			os<<x.Translate(x.GetKey());
		}while(x.GoNextK());
	}
	return os;
}


