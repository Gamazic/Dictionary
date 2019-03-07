/*
 * OrtList.cpp
 *
 *  Created on: 26 февр. 2019 г.
 *      Author: nikit
 */

#include "OrtList.h"

#include <string>
#include <iostream>
using namespace std;

OList::OList(){
	Head=NULL;
	CurrentKey=NULL;
	CurrentValue=NULL;
}

 OList:: ~OList(){}

bool OList::isEmpty(){
	if(Head==NULL)
		return true;
	else
		return false;
}


bool OList::VIsEmpty(){
	if(isEmpty())
		return true;
	else{
		if(CurrentKey->Trail==NULL)
			return true;
		else
			return false;
	}
}

bool OList:: findEl(string EWord){
	if(!isEmpty()){
		GoHead();
		do{
			if(CurrentKey->EWord==EWord)
				return true;
		}while(GoNextK());
	}
	return false;
}


bool OList:: GoNextK(){
	if(isEmpty())
		return false;
	else{
		if(CurrentKey->Next!=NULL){
			CurrentKey=CurrentKey->Next;
			CurrentValue=CurrentKey->Trail;
			return true;
		}
		else
			return false;
	}
}





bool OList:: GoNextV(){
	if(VIsEmpty())
		return false;
	else{
		if(CurrentValue->Next!=NULL){
			CurrentValue=CurrentValue->Next;
			return true;
		}
		else
			return false;
	}
}

void OList:: GoHead(){
	if(!isEmpty()){
		CurrentKey=Head;
		CurrentValue=CurrentKey->Trail;
	}
}

void OList:: DeleteCurV(){
	//случай, когда в текущем звене нет висюльки
	if(VIsEmpty()){
		return;
	}
	else{
		//когда CurrentQ- первый элемент в висюльке
		V *el=CurrentValue;
		if(CurrentKey->Trail->RWord==CurrentValue->RWord){
			CurrentKey->Trail=el->Next;
			el->Next=NULL;
			delete el;
		}
		else{
			CurrentValue=CurrentKey->Trail;
			while(CurrentValue->Next->RWord!=el->RWord){
				GoNextV();
			}
			CurrentValue->Next=el->Next;
			el->Next=NULL;
			delete el;
		}
	}
}

void OList::DeleteAllV(){
	while(!VIsEmpty()){
		CurrentValue=CurrentKey->Trail;
		DeleteCurV();
	}
}

void OList::DeleteCurK(){
	if(isEmpty()){
		return;
	}
	else{
		K *el=CurrentKey;
		if(CurrentKey==Head){
			Head=CurrentKey->Next;
			DeleteAllV();
			CurrentKey=Head;
			el->Next=NULL;
			delete el;
		}
		else{
			//el- копия ссылки на текущий элемент

			DeleteAllV();
			GoHead();
			while(CurrentKey->Next->EWord!=el->EWord){
				GoNextK();
			}
			//CurrentP-звено перед удаляемым элементом
			CurrentKey->Next=el->Next;
			el->Next=NULL;
			delete el;
		}
	}
}

bool OList:: AddK(string EWord){
	if(isEmpty()){
		Head=new K(EWord);
		CurrentKey=Head;
		CurrentValue=CurrentKey->Trail;
		return true;
	}
	else if(!findEl(EWord)){
		K *el=new K(EWord);
		CurrentKey->Next=el;
		CurrentKey=CurrentKey->Next;
		CurrentValue=CurrentKey->Trail;
		return true;
	}
	else{
		return false;
	}
}

//добавляет звено висюльки к текущему звену гирлянды
bool OList:: AddV(string RWord){
	if(isEmpty()){
		return false;
	}
	else{
		V *el=new V(RWord);
		if(VIsEmpty()){
			CurrentKey->Trail=el;
			CurrentValue=el;
			return true;
		}
		else{
			CurrentValue=CurrentKey->Trail;
			do{
				if(RWord==CurrentValue->RWord)
					return false;
			}while(GoNextV());
			CurrentValue->Next=el;
			return true;
		}
	}
}

bool OList::AddEnglishWord(string EnglishWord){
	if(AddK(EnglishWord))
		return true;
	else
		return false;
}

bool OList:: AddTranslate(string EnglishWord, string RussianWord){
	if(AddK(EnglishWord)){
		if(AddV(RussianWord)){
			return true;
		}
		else
			return false;
	}
	else{
		if(AddV(RussianWord)){
			return true;
		}
		else
			return false;
	}
}



string OList:: Translate(string EnglishWord){
	if(isEmpty())
		return "";
	if(findEl(EnglishWord)){
		string translates="";
		if(!VIsEmpty()){
			do{
				translates+=CurrentValue->RWord+" ";
			}while(GoNextV());
			return translates;
		}
		else{
			return " ";
		}
	}
	else
		return "";
}

void OList::DeleteEnglishWord(string EnglishWord){
	if(isEmpty())
		return;
	else{
		if(findEl(EnglishWord)){
			DeleteCurK();
		}
	}
}

void OList::DeleteTranlate(string EnglishWord,string RussianWord){
	if(isEmpty())
		return;

	if(findEl(EnglishWord)){
		if(VIsEmpty())
			return;
		else{
			do{
				if(CurrentValue->RWord==RussianWord){
					DeleteCurV();
					return;
				}
			}while(GoNextV());
		}
	}
}



