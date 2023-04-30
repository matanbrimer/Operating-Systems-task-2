#include <stdio.h>
#include <string.h>
#include "mylibrary.h"

//convert all chars to the 3-rd next char
void codecB(char text[],char flag[],int size){
    if(strcmp(flag, "encode") == 0){
        for (size_t i = 0; i < size; i++)
        {
            text[i] = text[i] + 3;
        }  
    }
    else if(strcmp(flag, "decode") == 0){    
        for (size_t i = 0; i < size; i++)
        {
            text[i] = text[i] - 3;
        }  
    }
}


// int main(){

//     char t[35] = "ACF()~";
//     char *p =t;
//     codecB(p);

   
//         printf("%s",p);
    
    
// printf("\n");

// // codecA(p);

// //       printf("%s",p);
    
    
// // printf("\n");
// return 1;
// }