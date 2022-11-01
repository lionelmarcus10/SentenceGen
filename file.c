//
// Created by Lionel on 27/10/2022.
//

#include "file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// fonction pour lire un fichier
// autoriser les caracteères spéciaux et mettre en parametre le fichier ou moyen
// de varier le link du file
void showFile(){

    const char * dico = "../test.txt";

    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        while (fgets(buf, sizeof buf, Dico) != NULL)
            printf("%s", buf);
    }
    fclose(Dico);
};

// fonction pour afficher les colonnes d'un fichier ( chaque colonne séparé par une tabulation)
// autoriser les caracteères spéciaux et mettre en parametre le fichier ou moyen
// de varier le link du file
void showFileColumn(int column){

    char * dico = "../test.txt";
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        while (fgets(buf, sizeof buf, Dico) != NULL){
            char *current_column = strtok(buf, "\t");
            int col = 1;
            while(col < column) {
                current_column = strtok(NULL, "\t");
                col++;
            }
            printf("%s",current_column);
        }
    }
    fclose(Dico);
};

// fonction pour trouver les formes fléchis d'un mot à partir de la base et afficher
// autoriser les caracteères spéciaux et mettre en parametre le fichier ou moyen
// de varier le link du file
void showVariantByBaseInFile(char * base){

    char * dico = "../test.txt";
    int base_Col = 2;
    int variant_Col = 1;
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        int found = 0;
        while (fgets(buf, sizeof buf, Dico) != NULL){
            // recuperer les deux colonnes de la ligne
            char *var_col_element = strtok(buf, "\t");
            char *base_col_element = strtok(NULL,"\t");
            // afficher le variant si la base correspond
            if(strcmp(base, base_col_element) == 0) {
                found = 1;
                printf("%s\n ", var_col_element);
            }
        }
        if(found == 0)
            printf("Pas de forme flechis dans le dictionnaire");
    }
    fclose(Dico);
};

//- fonction pour trouver la base d'un mot à partir de la forme fléchis et afficher
// autoriser les caracteères spéciaux et mettre en parametre le fichier ou moyen
// de varier le link du file
void showBaseByVariantInFile(char * variant){

    char * dico = "../test.txt";
    int base_Col = 2;
    int variant_Col = 1;
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        int found = 0;
        while (fgets(buf, sizeof buf, Dico) != NULL){
            // recuperer les deux colonnes de la ligne
            char *var_col_element = strtok(buf, "\t");
            char *base_col_element = strtok(NULL,"\t");
            // afficher la base si la forme fléchis correspond
            if(strcmp(var_col_element, variant) == 0) {
                found = 1;
                printf("%s\n", base_col_element);
            }
        }
        if(found == 0)
            printf("Pas de forme de base dans le dictionnaire");
    }
    fclose(Dico);
};