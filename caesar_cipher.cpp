#include<iostream>
#include <string>
using namespace std;
string encrypt(string plaintext, int shift);
string caseAlphabet(string text , int shift,string choice);
int main (){
	int shift;
	string text;
	
	cout << "Plain Text : ";
	getline (cin,text);
	cout << "Shift : ";
	cin >> shift;
	
//	set uppercase and lowercase alphabet
	string encrypt = caseAlphabet(text ,shift,"encrypt");
	cout <<"Encrypt : "<<encrypt<< endl;
	string  decrypt= caseAlphabet(encrypt ,shift,"decrypt");
	cout << "Decrypt : " << decrypt << endl;
}
char encrypt(char plaintext, int shift,int max_alphabet,int min_alphabet){
	
	char value = plaintext+shift;
	if(value > max_alphabet){
		value =   (value-max_alphabet)+(min_alphabet-1) ;
	}
	return value;
}
char decrypt(char plaintext, int shift,int max_alphabet,int min_alphabet){
	
	char value = plaintext-shift;
	if(value < min_alphabet){
		value =   (max_alphabet-value)+(min_alphabet-1) ;
	}
	return value;
}
string caseAlphabet(string text , int shift,string choice){
	string value="";	
	for (int a = 0 ; a < text.length(); a++){
		if(int(text[a]) >= 97 && int(text[a]) <= 122){
			if(choice == "encrypt"){
				value += encrypt(text[a],shift,122,97) ;	
			}else if(choice == "decrypt" ){
				value += decrypt(text[a],shift,122,97) ;
			}
		}else if(int(text[a]) >= 65 && int(text[a]) <= 90){
			if(choice == "encrypt"&& text[a]){
				value += encrypt(text[a],shift,122,97) ;	
			}else if(choice == "decrypt"&& text[a]){
				value += decrypt(text[a],shift,122,97) ;
			}
		}

	}
	return value;
}
