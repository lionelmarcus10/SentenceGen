//
// Created by Lionel on 27/10/2022.
//
#include "struct.h"
#include "tag.h"

#ifndef SENTENCEGEN_FILE_H
#define SENTENCEGEN_FILE_H
void showBaseByVariantInFile(char * variant);
void thirColFirstParserShow();
void thirColFirstParser2Show();
p_child child_horizontal(char val,p_node rac);
void add_Variant_By_Base_In_File(char * base, char * typeName, p_node form_start);
void remplir_arbre(p_node racine ,char * mot,char * typeName);
t_tree extractWordByTypeInDictionnary(p_node racine ,char * typeOfTree);
#endif //SENTENCEGEN_FILE_H
