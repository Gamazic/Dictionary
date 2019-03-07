/*
 * OrtList.h
 *
 *  Created on: 26 февр. 2019 г.
 *      Author: nikit
 */

#ifndef ORTLIST_H_
#define ORTLIST_H_


#include <string>
using namespace std;

class OList{
private:
	struct V{
		V *Next;
		string RWord;
		V(string RussianWord){
			RWord=RussianWord;
			Next=NULL;
		}
	};
	struct K{
		K *Next;
		V *Trail;
		string EWord;
		K(string EnglishWord){
			EWord=EnglishWord;
			Trail=NULL;
			Next=NULL;
		}
	};

	K *Head;
	K *CurrentKey;
	V *CurrentValue;
public:

	OList();
	~OList();

	bool VIsEmpty();
	bool AddK(string EWord);
	void DeleteCurK();
	void DeleteCurV();
	void DeleteAllV();
	bool AddV(string RWord);
	bool GoNextK();
	bool GoNextV();
	void GoHead();
	bool findEl(string EWord);
	string GetKey(){return CurrentKey->EWord;}
//	string GetValue(){return CurrentValue->RWord;}


	bool isEmpty();
	bool AddEnglishWord(string EnglishWord);
	bool AddTranslate(string EnglishWord,string RussianWord);
	void DeleteTranlate(string EnglishWord,string RussianWord);
	void DeleteEnglishWord(string EnglishWord);
	string Translate(string EnglishWord);
};






#endif /* ORTLIST_H_ */
