//
//  main.c
//  newcoo2old
//
//  Created by Alexander Kompch on 03.03.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    char *infile = handle_cmdlargs(argc, argv);
    coords *newcoo = read_newcoo(infile);
    
    conv_tbl *cvt = count_noe(newcoo);
    
    
    


    coords_free(newcoo);
    free(infile);
    return 0;
}
