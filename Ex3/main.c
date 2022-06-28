#include <stdio.h>
#include <string.h>
#include "stringProg.h"
#define TXT 1024
#define WORD 30
int main(){
  char words[WORD];
  char txts[TXT];
  scanf ("%[^\n]", words);
  scanf ("%[^~]", txts);
  int wLen = strlen (words);
  int tLen = strlen (txts);
  char *w = words;
  char *t = txts;
  printf ("Gematria Sequences: " );
  G(w,t,wLen,tLen);
  printf("\n");
  printf("Atbash Sequences: " );
  AB(w,t,wLen,tLen);
  printf("\n");
  printf("Anagram Sequences: " );
  A(w,t,wLen,tLen);
  
  
  return 0;
}
