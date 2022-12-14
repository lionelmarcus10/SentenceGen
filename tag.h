#ifndef SENTENCEGEN_TAG_H
#define SENTENCEGEN_TAG_H

#define P1_TB  1
#define P2_TB  2
#define P3_TB  4
#define PL_TB  8
#define SG_TB  16
#define Mas_TB   32
#define IPre_TB  64
#define InvGen_TB 128
#define IPSim_TB   256
#define IImp_TB    512
#define PPre_TB    1024
#define Fem_TB     2048
#define SImp_TB    4096
#define  IFut_TB   8129
#define  Inf_TB    16384
#define CPre_TB     32768
#define  PPas_TB   65536
#define  SPre_TB   131072
#define  Imp_TB    262144
#define InvPL_TB   524288
#define ImPre_TB   1048576

#define  Card_TB   2097152
#define Nom_TB     4194304

#define P1   "P1"
#define P2   "P2"
#define P3    "P3"
#define PL    "PL"
#define SG    "SG"
#define Mas    "Mas"
#define IPre   "IPre"
#define InvGen  "InvGen"
#define IPSim   "IPSim"
#define IImp    "IImp"
#define PPre    "PPre"
#define Fem      "Fem"
#define Fem3    "3Fem"
#define Mas3    "3Mas"
#define SImp     "SImp"
#define  IFut    "IFut"
#define  Inf    "Inf"
#define CPre   "CPre"
#define  PPas   "PPas"
#define  SPre    "SPre"
#define  Imp     "Imp"
#define InvPL  "InvPL"
#define ImPre "ImPre"
#define  Card  "Card"
#define  Nom    "Nom"
#define Pre "Pre"
#define Adj "Adj"
#define Int  "Int"
#define Pro "Pro"
#define Det  "Det"
#define Con "Con"
#define QPro  "QPro"
#define Abr "Abr"
#define Adv "Adv"
#define Ono "Ono"
#define Ver "Ver"
#define Conj "Conj"

int getFlags(char *tag);

#endif