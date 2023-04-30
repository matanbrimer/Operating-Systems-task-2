#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int cmp(char* nameFile1,char* nameFile2,char flag){
    
    FILE *file_1; 
    FILE *file_2; 
    char txt1[2056];
    char txt2[2056];
    file_1 = fopen(nameFile1, "rb");
    file_2 = fopen(nameFile2, "rb");
    int result =20;
    bool end_file1 =false,end_file2 = false;
    if (file_1 == NULL || file_2 == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (!feof(file_1) && !feof(file_2)) {
        fgets(txt1, 2056, file_1);
        fgets(txt2, 2056, file_2);
        if(flag == 'i'){
     
            int i =0, j=0;
            while(txt1[j] != '\0'){
                txt1[j] = tolower(txt1[j]);
                j++;
            }
            while(txt2[i] != '\0'){
                txt2[i] = tolower(txt2[i]);
                i++;
            }
        }
        result = strcmp(txt1, txt2);
        if(result != 0){
            return 1;
        }
    }
    //check the ifff
  if(feof(file_1))end_file1=true;
  if(feof(file_2))end_file2=true;
   if(!end_file1 || !end_file2)return 1;
    return 0;
}
int main(int argc, char *argv[]){
    if(argc < 3){
        printf("The file names are missing\n");
        exit(1);
    }
    char *namefile1 = argv[1];
    char *namefile2 = argv[2];
    if(argc == 3){
        printf("%d\n", cmp(namefile1,namefile2,' '));   
    }
    else if(argc == 4 )
    {
        char *flag =  argv[3];
        if(flag[1] == 'v'){
            if(cmp(namefile1,namefile2,' ') == 0)
                printf("equal\n");
            else
                printf("distinct\n");

        }
        else if(flag[1] == 'i'){
            printf("%d\n",cmp(namefile1,namefile2,'i')); 
        }
    }
    else if(argc == 5 ){
        char *flag =  argv[3];
        char *flag2 =  argv[4];
        if((flag[1] == 'i' || flag[1] == 'v') && (flag2[1] == 'i' || flag2[1] == 'v'))
        {
            if(cmp(namefile1,namefile2,'i') == 0)
                printf("equal\n");
            else
                printf("distinct\n");
            }
    }
    else{
        printf("ERROR");
    }

    return 0;
}
