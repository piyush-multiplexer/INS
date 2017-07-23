3 Files

PlainText.txt input file

cipher.txt encrypted cipher text

plain.txt decrypted file same as input file

<code>
﻿#include"stdio.h"#include"ctype.h"#include"string.h"void decrypt (char cipher[], int key) {  int i = 0;  while (cipher[i] != '\0'&& i<strlen(cipher)) {    if ((cipher[i] - key) >= 65 && (cipher[i] - key) <= 90) {      cipher[i] -= (key);//capital    }     else if ((cipher[i] - key) >= 97 && (cipher[i] - key) <= 122) {      cipher[i] -= (key);//small    }    else if(isspace(cipher[i])){      cipher[i] = cipher[i];    }	    else {      cipher[i] -= (key - 26);     }    i++;  }  printf("\nDeCipher: %s", cipher);}void encrypt (char input[], int key) {  int i = 0;  while (input[i] != '\0'&& i<strlen(input)) {    if ((input[i] + key) >= 65 && (input[i] + key) <= 90) {	  input[i] += (key);//capital    }     else if ((input[i] + key) >= 97 && (input[i] + key) <= 122) {	  input[i] += (key);//small    }    else if(isspace(input[i])){      input[i] = input[i];    }	    else {      input[i] += (key - 26);     }    i++;  }  printf("\nCipher: %s", input);  decrypt(input, key);}int main () {	char input[50];	int key;	printf("Enter Plaintext: ");	gets(input);	printf("Enter Key: ");	scanf("%d", &key);	encrypt (input, key);	return 0;}
</code>

