//
//  write_coo.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "write_oldcoo.h"

int write_oldcoo(char *filename, coords *coo) {
    FILE *FP;
    int i=0;
    
    printf("\nwrite_oldcoo: filename = %s",filename);
    
        // format(i6,1x,i2,5(1x,g13.6))
        //write(11,9000)i,typ(i),a(i),b(i),c(i),0.0,1.0
    
    if (coo == NULL) return EXIT_FAILURE;
       
    FP=fopen(filename, "wt");
    if (FP == NULL) {
        printf("\n***   write_oldcoo:Could not open <%s>.", filename);
        return EXIT_FAILURE;
    }
    for(i=0;i<coo->nat;i++) {
        fprintf(FP, "%6d %2d %+13.6f %+13.6f %+13.6f %+13.6f %+13.6f\n", coo->at[i]->n, coo->at[i]->atn, coo->at[i]->pnt.x, coo->at[i]->pnt.y, coo->at[i]->pnt.z, 0.0, 1.0);
    }
    printf("\n***write_oldcoo: here!!!");
    fclose(FP);
    
    return EXIT_SUCCESS;
}