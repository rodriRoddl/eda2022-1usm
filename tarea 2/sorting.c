#include "tweets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertionSort ( tweet arr [ ] , int n ){
int i, j;
tweet key;
for ( i = 1 ; i < n ; i ++) {
    key = arr [i] ;
    j  = i - 1 ;
    while ( j >= 0 && arr[j].fecha > key.fecha ) {
        arr [j+1] = arr [j] ;
        j --;
    }
    arr [j + 1] = key ;
    }
}
