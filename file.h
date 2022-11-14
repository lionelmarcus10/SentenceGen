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
char* mot_a_chercher();
p_child chercher_un_enfant(p_node, char);
void  rechercher_un_mot(p_node, char*, char*);
void  rechercher_global_by_base(p_node,p_node,p_node,p_node,p_node,p_node,p_node,p_node,p_node,p_node,p_node,p_node,p_node);
#endif //SENTENCEGEN_FILE_H
