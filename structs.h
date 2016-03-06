//
//  structs.h
//  mklatc
//
//  Created by Alexander Kompch on 03.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef mklatc_structs_h
#define mklatc_structs_h

#include "conversiontable_helper.h"

//typedefstructs
typedef struct {
    double x;
    double y;
    double z;
} vec;

typedef struct {
    int n;
    char esymb[2];
    int atn;
    vec pnt;
} atom;

typedef struct {
    int nat;
    vec boxL;
    atom **at;
} coords;


typedef struct {
    int noe;
    void *cvt;
    char *infile;
    char *outfile;
} parameters;

#endif


