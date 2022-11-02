#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>



void main(){

    wchar_t c = "é";
    setlocale(LC_ALL, "");
    wprintf(L"%lc\n", c);
    printf("\nHello World!");
}


