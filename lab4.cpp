#include <iostream>
#include <string>
#include <bitset>

using namespace std;

//Prototipos de Vigenere

string codeVigenere(char* ,char* ,int , int);
int contLetter(char* ,int );
void changeLetter(char** ,char*,char*, int ,int);
//funcion para el cifrado del cesar
string codeCesar(string);
//funcion para la asignacion de numeros
int* numbers (string);

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
		int* numberText = new int [text.size()];
		int* numberWord = new int [word.size()];
		numberText = numbers(text);
		numberWord = numbers(word); 
		//VIGE
		cout<<"Cifrado de Vigenere";
		char* textos = new char[text.size()];
		char* claves = new char[word.size()];
		cout<<codeVigenere(textos , claves,text.size(),word.size());
		cout<<"Desea continuar [s/n]: ";
		cin>>answer;			
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
	int* number = new int [word.size()];
	for (int i=0; i<word.size(); i++){
		number[i] = word[i];
	}	
	return number;
}


//Metodo codigo vigenere
string codeVigenere(char* texto , char* clave, int sizeText , int sizeClue){
   char** matrixLetter = new char* [25]; 
   for(int i  = 0 ; i<25 ; i++){
					  matrixLetter[i] = new char[25];

   }
   int textSize;//Tamano de las palabras

   int value = 65;//Para ingresar el valor ascii
   int start = 0 ; //Hace empezar en la siguiente letra
   //int* numberColum = new int [sizeClue]; //Numero de la columna de cada palabra

   //Llenado de matriz con el abecedario
   for(int i= 0 ;i <= 24 ; i++){
      value = value+start;
      for(int j = 0 ;j <= 24 ;j++ ){
         if(value <=90){

            matrixLetter[i][j] = value;
            value++;
         }else{
            value=65;
         }
      }
      start++;
   
   }   
   //Sacamos el tamano de los string , NO SE OCUPA
   //textSize = contLetter(texto ,sizeText );  
   //Cambiando letra
   changeLetter(matrixLetter,texto,clave,sizeText ,sizeClue);
   string palabra;
   for(int i = 0 ; i<sizeText ; i++){
      palabra+=texto[i];
   }   
   return palabra;

}


//Contar letras
int contLetter(char* text  , int sizeText){
   int cont = 0 ; 
   for(int i = 0 ; i<sizeText ; i++ ){
      if(text[0] !='\0'){
         cont ++; 

      }   

   }   
   return cont;

}

//Metodo que intercambia las palabras 

//Matriz de abecedario , texto , clave.
void changeLetter(  char** matriz , char* text , char* clue,int sizeText,int sizeClave){
      int flag = 0 ; //Para moverse entre columnas
      for(int i = 0 ; i <=sizeText ; i++){
         if(flag< sizeClave && text[i]!='\0'){// y que sea distinto de espacio en blanco
            int colum =clue[flag]-65;
            int fila = text[i]-65;
            text[i] = matriz[fila][colum];
         }else{
            flag = 0;
         }
      }   
}
