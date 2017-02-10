#include <iostream>
#include <string>
#include <bitset>

using namespace std;

//funcion para el cifrado del cesar
string codeCesar(string);
//funcion para la asignacion de numeros
int* numbers (sring);

int main()
{
	char answer = 's';
	string word;
	string text;
	while (answer=='s'){
		cout<<"Ingrese la palabra clave: ";
		cin>>word;
		cout<<"Ingrese el texto a cifrar: ";
		getline(cin,text);
		//TODO: cifrado de vigenere
		
		//TODO: cifrado del cesar

		//TODO: cifrado de xor
		int numberText = new int [text.size()];
		int numberWord = new int [word.size()];
		numberText = 

	}
	return 0;
}

//funcion para el cifrado del cesar
string codeCesar(string word)
{
	int number;//numero para encontrar la letra 
	int numberLetter;//numero de la letra de la cadena
	for (int i=0; i<word.size(); i++){
		if (word[i]!=' '){
			numberLetter = word[i];
			number = numberLetter + 13;
			if (number>122){//validacion de cuando se sobrepasa el abecedario en la tabla acsii
				int number2 = number - 122;
				number = 96 + number2;
				word[i] = number;
			}
			else {
				word[i]=number;
			}
		}
		else {
			word[i] = word[i];
		}
	}
	return word;	
}

int* numbers (string word)
{
	int number = new int [word.size()];
	for (int i=0; i<word.size(); i++){
		number[i] = word[i];
	}	
	return number;
}
