#include <stdio.h>
#include <stdbool.h>

// Ejercicio 5
int findString (const char source[], const char find[]){
   int result;
   bool ifFlag = false;
   for (size_t i = 0; source[i] != '\0' && ifFlag != true; i++)
      if (source[i] == find[0] ){
         result = i ;
         for (size_t j = 0, k = i; source[k] == find[j] && source[k] !='\0'; j++, k++)
            ifFlag = (find[j + 1] == '\0') ? true : false;
      }

   result = (ifFlag == true) ? result : -1;
   return result;
}
// Ejercicio 6
void removeString (char text[], int start, int remove){

   for (size_t i = start, j = 0; j < remove; i++, j++)
      text[i] = 1;
}

// Ejercicio 7
void insertString (char text[], const char insert[], int start, bool repFlag){
   char temp[40];
   size_t i, j ;
   //El problema con temp es que empieza a copiar desde start. Solución:
   if (repFlag == true){
      for (i = start, j = 0; text[i] != '\0' ; i++)
         if(text[i] != 1){
            temp[j] = text[i]; 
            j++;
         }
   }else
   for (i = start, j = 0; text[i] != '\0' ; i++, j++)
      temp[j] = text[i];

   temp[j] = '\0';
   for ( i = 0, j= start; insert[i] != '\0'; i++, j++)
      text[j] = insert[i];

   //Si no colocaramos el if, se usaria uno de los espacios eliminados cuando insert fuera solo un caracter.
   if (insert[1] == '\0')
         text = text;
   else 
      for ( i = 0; temp[i] != '\0'; i++, j++)
         text[j] = temp[i];

   // printf("\t%i\n",stringLenght(text));
       
}

// Ejercicio 8
void replaceString(char source[], const char orginal[], const char replace[]){
   int start, orgLeng;
   bool stillFound;

   do{
   start = findString(source, orginal);      
   for (orgLeng = 0; orginal[orgLeng] != '\0'; orgLeng++)
      1;

   if (start == -1){
      source = source;
      stillFound = false;
   }else{ 
      removeString(source, start, orgLeng);
      insertString(source, replace, start, true);
      stillFound = true;
   }
   }while (stillFound);
}
int main(void){
   char text6 [32] = "Dulce Arelibs.";

   replaceString (text6, "l", "p");

   printf("\v%s\n", text6);
   

   return 0;   
}