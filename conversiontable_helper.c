//
//  conversiontable_helper.c
//  newcoo2old
//
//  Created by Alexander Kompch on 03.03.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "conversiontable_helper.h"

conv_tbl *cvt_init(int nset) {
    int i = 0, j = 0;
    int m = 2;
    conv_tbl *cvt = (conv_tbl*)calloc(1, sizeof(conv_tbl));
    if (cvt == NULL) {
        printf("\n***   init_cvt: calloc failed. Will exit!");
        exit(EXIT_FAILURE);
    }
    cvt->size1 = nset;
    cvt->size2 = m;
    cvt->tda = m;
    cvt->data = calloc(nset * m, sizeof(int));
//    printf("\nsizeof(int) = %lu", sizeof(int));
//    printf("\nn * m * sizeof(int) = %lu", n * m * sizeof(int));
//    printf("\ncvt->data = %p", cvt->data);
//    printf("\n");
    for (i = 0; i < cvt->size1; i++) {
        for (j = 0; j < cvt->size2; j++) {
            i++;
            *(cvt->data + (i * cvt->tda + j)) = 0;
//            *(cvt->data + (n * cvt->tda + m)) = i;
//            printf("n = %d m = %d memory# = %2lu pointer2element = %p\n", n, m, (n * cvt->tda) + m, cvt->data + (n * cvt->tda + m));
//            printf("n = %d m = %d pointer2element = %p content = %d\n", n, m, cvt->data + (n * cvt->tda + m), *(cvt->data + (n * cvt->tda + m)));
        }
    }
    return cvt;
}

int cvt_free(conv_tbl *given) {
    free(given->data);
    free(given);
    return EXIT_SUCCESS;
}

void cvt_set(conv_tbl *given, int n, cvt_pair set) {
    if (given == NULL) {
        printf("\n***   cvt_init: calloc failed. Will exit!");
        exit(EXIT_FAILURE);
    } else if (n >= given->size1) {
        printf("\n***   cvt_set: row > allocated. Will exit!");
        exit(EXIT_FAILURE);
    } else if (given->size2 < 2) {
        printf("\n***   cvt_set: less than 2 columns allocated. Will exit!");
        exit(EXIT_FAILURE);
    }
    *(given->data + n * given->tda + 0) = set.atn;
    *(given->data + n * given->tda + 1) = set.att;
}

cvt_pair cvt_get(conv_tbl *given, int n) {
    cvt_pair pair = {.atn=0, .att=0};
    if (given == NULL) {
        printf("\n***   cvt_get: calloc failed. Will exit!");
        exit(EXIT_FAILURE);
    } else if (n >= given->size1) {
        printf("\n***   cvt_get: row > allocated. Will exit!");
        exit(EXIT_FAILURE);
    } else if (given->size2 < 2) {
        printf("\n***   cvt_get: less than 2 columns allocated. Will exit!");
        exit(EXIT_FAILURE);
    }
    pair.atn = *(given->data + n * given->tda + 0);
    pair.att = *(given->data + n * given->tda + 1);
    
    return pair;
}

conv_tbl *cvt_askuser(coords *given) {
    if (given == NULL) {
        printf("\n***   cvt_askuser: newcoo not allocated. Will exit!");
        exit(EXIT_FAILURE);
    }
    int noe = count_noe(given);
    
        
        
        
    return cvt;
}

