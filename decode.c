#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main(int argc, char *argv[]){

    if(argc == 3){

        int size =(int) strlen(argv[2]);
        char text[size+1] ;
        strcpy(text,argv[2]);
        char *name_lib =argv[1];

        if(strcmp(name_lib, "codecA") == 0){
            void *lib;
            void (*my_function)(char[],int);
            lib = dlopen("./codecA.so", RTLD_LAZY);
            
            if (!lib) {
                printf("Error: %s\n", dlerror());
                return 1;
            }
            my_function = (void (*)(char[],int)) dlsym(lib, "codecA");
            if (!my_function) {
                printf("Error: %s\n", dlerror());
                dlclose(lib);
                return 1;
            }
            
            my_function(text,size);
            printf("%s\n",text);
            dlclose(lib);
        }
        else if(strcmp(name_lib, "codecB") == 0){
            void *lib;
            void (*my_function)(char[],char[],int);
            lib = dlopen("./codecB.so", RTLD_LAZY);
            if (!lib) {
                printf("Error: %s\n", dlerror());
                return 1;
            }
            my_function = (void (*)(char[],char[],int)) dlsym(lib, "codecB");
            if (!my_function) {
                printf("Error: %s\n", dlerror());
                dlclose(lib);
                return 1;
            }
            char de[] ="decode";
            my_function(text,de,size);
            printf("%s\n",text);
            dlclose(lib);
        }


    }
    else{
        printf("Error:will try to rewrite and run");
        exit(1);
    }

    return 0;
}