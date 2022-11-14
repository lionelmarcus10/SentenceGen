#include "tag.h"
#include <string.h>

#ifdef _WIN32
#define strtok_r(s, d, c) strtok_s(s, d, c)
char *strtok_s(char *str, const char *delimiters, char **context);
#endif

int getFlags(char *tag)
{
    char *saveptr;
    char *flag = strtok_r(tag, "+", &saveptr);
    int flags = 0;
    do
    {
        if (strcmp(flag, P1) == 0)
            flags += P1_TB;
        else if (strcmp(flag, P2) == 0)
            flags += P2_TB;
        else if (strcmp(flag, P3) == 0)
            flags += P3_TB;
        else if (strcmp(flag, Mas) == 0)
            flags += Mas_TB;
        else if (strcmp(flag, Fem) == 0)
            flags += Fem_TB;
        else if (strcmp(flag, PL) == 0)
            flags += PL_TB;
        else if (strcmp(flag, SG) == 0)
            flags += SG_TB;
        else if (strcmp(flag, IPre) == 0)
            flags += IPre_TB;
        else if (strcmp(flag, IImp) == 0)
            flags += IImp_TB;
        else if (strcmp(flag, SPre) == 0)
            flags += SPre_TB;
        else if (strcmp(flag, IPSim) == 0)
            flags += IPSim_TB;
        else if (strcmp(flag, PPre) == 0)
            flags += PPre_TB;
        else if (strcmp(flag, SImp) == 0)
            flags += SImp_TB;
        else if (strcmp(flag, PPas) == 0)
            flags += PPas_TB;
        else if (strcmp(flag, IFut) == 0)
            flags += IFut_TB;
        else if (strcmp(flag, CPre) == 0)
            flags += CPre_TB;
        else if (strcmp(flag, Inf) == 0)
            flags += Inf_TB;
        else if (strcmp(flag, InvGen) == 0)
            flags += InvGen_TB;
        else if (strcmp(flag, InvPL) == 0)
            flags += InvPL_TB;
        else if(strcmp(flag,Imp) == 0)
            flag += Imp_TB;
        else if(strcmp(flag,ImPre ) == 0)
            flag += ImPre_TB;
    } while ((flag = strtok_r(NULL, "+", &saveptr)));
    return flags;
}