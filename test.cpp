#include <stdio.h>

int main() {
   char *p[2][2] = {"abc", "defg", "jklmno", "pqrs"};

   char h, e, l, o;
   char Hi = *(*(*(p)+1)+3)+1;

   printf("%c", Hi);
   //printf("%c%c%c%c%c!]\n", h,e,l,l,o);
}