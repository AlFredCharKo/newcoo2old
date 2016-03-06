//
//  main.c
//  newcoo2old
//
//  Created by Alexander Kompch on 03.03.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    char outfile[MAX_LEN];
    char *infile = handle_cmdlargs(argc, argv);
    trim(infile);
    coords *newcoo = read_newcoo(infile);
    conv_tbl *cvt = get_noe(newcoo);
    cvt_askuser(cvt);
    coords *oldcoo = convert_new2old(newcoo, cvt);
    
    printf("\nenter output filename: ");
    scanf("%254s", outfile);
    trim(outfile);
    parameters *pars = (parameters*)calloc(1, sizeof(parameters));
    pars->infile = (char*)calloc(strlen(infile) + 1, sizeof(char));
    strcpy(pars->infile, infile);
    pars->outfile = (char*)calloc(strlen(outfile) + 1, sizeof(char));
    strcpy(pars->outfile, outfile);
    pars->noe = cvt_size(cvt);
    pars->cvt = cvt;
    
    
    print_pars(pars);
    write_oldcoo(outfile, oldcoo);
    
    
    
    


    coords_free(newcoo);
    coords_free(oldcoo);
    free(pars->infile);
    free(pars->outfile);
    cvt_free(cvt);
    free(pars);
    free(infile);
    return 0;
}
