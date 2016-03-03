//
//  handle_cmdlargs.c
//  MkHexLat
//
//  Created by Alexander Kompch on 26.02.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "handle_cmdlargs.h"


char* handle_cmdlargs(int argc, const char *argv[]) {

    if (argc < 2) {
        printf("\n***   handle_cmdlargs: no input file given. Will exit!");
        exit(EXIT_FAILURE);
    } else {
        char *f=(char*)calloc(strlen(argv[1])+1, sizeof(char));
        if (f == NULL) {
            printf("\n***   handle_cmdlargs: malloc input file failed. Will exit");
            exit(EXIT_FAILURE);
        }
        printf("\n***   handle_cmdlargs: strlen(argv[1])*sizeof(char)=%zu",strlen(argv[1])*sizeof(char));
        strcpy(f,argv[1]);
        return f;
    }
}
