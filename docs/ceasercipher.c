#include"stdio.h"
#include"ctype.h"
#include"string.h"

FILE *cfp;
FILE *dfp;

void decrypt (char cipher, int key) {
    if ((cipher - key) >= 65 && (cipher - key) <= 90) {
      cipher -= (key);//capital
    } 
    else if ((cipher - key) >= 97 && (cipher - key) <= 122) {
      cipher -= (key);//small
    }
    else if(isspace(cipher)){
      cipher = cipher;
    }	
    else {
      cipher -= (key - 26); 
    }
  fprintf(dfp, "%c", cipher);
}

void encrypt (char input, int key) {
    if ((input + key) >= 65 && (input + key) <= 90) {
	  input += (key);//capital
    } 
    else if ((input + key) >= 97 && (input + key) <= 122) {
	  input += (key);//small
    }
    else if(isspace(input)){
      input = input;
    }	
    else {
      input += (key - 26); 
    }
  fprintf(cfp, "%c", input);
  decrypt(input, key);
}

int main () {
	FILE *fp;
	char filedata;
	int key;
        fp = fopen("PlainText.txt", "r");
        cfp = fopen("cipher.txt","w");
        dfp = fopen("plain.txt","w");
	if (fp == NULL) {
             printf("I couldn't open input file.\n");
             return 0;
        }else{
	      printf("Enter Key: ");
	      scanf("%d", &key);
	      while((filedata=fgetc(fp)) != EOF){
		      printf("%c",filedata);
		      encrypt (filedata, key);
	      }			
	}
	fclose(fp);
	fclose(cfp);
	fclose(dfp);
	return 0;
}


