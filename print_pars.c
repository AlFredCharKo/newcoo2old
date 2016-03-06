//
//  print_pars.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "print_pars.h"

int print_pars(parameters *pars)
{
    cvt_pair pair = {.atn = 0, .att = 0};
    printf("\n***   IN print_pars   ***\n");
    
    printf("\ninput file <%s>", pars->infile);
    printf("\noutput file: <%s>", pars->outfile);
    printf("\nnumber of elements found in %s: %d", pars->infile, pars->noe);
    printf("\n***conversion table***");
    for (int i = 0; i < cvt_size(pars->cvt); i++) {
        pair = cvt_get(pars->cvt, i);
        printf("\nconvert atomic number %3d to atom type %3d", pair.atn, pair.att);
    }
    
    
    printf("\n");
    return EXIT_SUCCESS;
}