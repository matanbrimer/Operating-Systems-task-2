#include <stdio.h>
#include <string.h>
#include "mylibrary.h"

void codecA(char text[],int size){

     
        for (size_t i = 0; i < size; i++)
        {
            if(text[i] >= 97 && text[i] <= 122){
                text[i] = text[i] - 32;
            }
            else if(text[i] >= 65 && text[i] <= 90){
                text[i] = text[i] + 32;
            }
            else{
                continue;
            }
        }      


}
