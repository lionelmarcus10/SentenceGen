//
// Created by Lionel on 27/10/2022.
//

#include "file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// fonction pour lire un fichier
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
// fonction pour afficher la nature des mots sur chaque colonne : uniq values
void thirColFirstParserShow(){
    int column = 3;
    char * dico = "../test.txt";
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        // creer un tableau pour stocker les differents types de chaque ligne
        char **tableau = NULL;
        int nbr = 10; //287976; 10
        tableau = malloc( sizeof(char*) * nbr);
        // allouer une taille à chaque case du tableau
        for (int i=0; i<nbr;i++) {
            tableau[i] = malloc(sizeof(char)*100);
        }
        // parcourir chaque ligne recuperer chaque type puis le mettre dans le tableau
        int k =0;
        while (fgets(buf, sizeof buf, Dico) != NULL){
            char *current_column = strtok(buf, "\t");
            int col = 1;
            while(col < column) {
                current_column = strtok(NULL, "\t");
                col++;
            }
            // mettre les types dans le tableau
            char *word_Type = strtok(current_column,":");
            int cleaner =0;
            // eviter les redondances
            char*temp = malloc(sizeof(char)*100);
            sprintf(temp,"%s",word_Type);
            for(int i =0;i<k;i++){
              if (strcmp(tableau[i],temp) == 0)
                 cleaner = 1;
            }
            if(cleaner == 0){
              sprintf(tableau[k],"%s",temp);
              k++;
            }
        };
        nbr = k;
        // afficher le nouveau tableau
        for(int v= 0;v<k;v++){
            printf("%s\n",tableau[v]);
        }
    }
    fclose(Dico);
};

// supprimer les redondances dans un tableau de char ** contenant des char *
char ** occDeleter(char ** tableau,int nbr){
    int clean;
    do{
        clean=1;
        for(int i=0 ; i<nbr-1; i++ ){
            for(int j=i+1;j<nbr;j++){
                if (strcmp(tableau[i],tableau[j]) == 0)
                {
                    for(int k=j;k<nbr;k++)
                        tableau[k] = tableau[k+1];
                    //free(tableau[nbr]);
                    clean = 0;
                    nbr--;
                }
            }
        }
    }while (clean!=1);
    for(int v= 0;v<nbr;v++)
        printf("%s",tableau[v]);
    return tableau;
};

// fonction pour afficher les differents types de conjugaison des mots sur chauque colonne : uniq values
void thirColFirstParser2Show(){
    int column = 3;
    char * dico = "dictionnaire_non_accentue.txt";
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        // creer un tableau pour stocker les differents types de chaque ligne
        char **tableau = NULL;
        int nbr = 287976; //287976; 10
        tableau = malloc( sizeof(char*) * nbr);
        // allouer une taille à chaque case du tableau
        for (int i=0; i<nbr;i++) {
            tableau[i] = malloc(sizeof(char)*100);
        }
        // parcourir chaque ligne recuperer chaque type puis le mettre dans le tableau
        int k =0;
        while (fgets(buf, sizeof buf, Dico) != NULL){
            char *current_column = strtok(buf, "\t");
            int col = 1;
            while(col < column) {
                current_column = strtok(NULL, "\t");
                col++;
            }
            // mettre les types dans le tableau
            char *word_Type = strtok(current_column,":");
            word_Type = strtok(NULL,"+");
            // supprimer les occurences
            char * start = malloc(100*sizeof(char));
            while(word_Type != NULL){
                char * temper = malloc(100*sizeof(char));
                sprintf(temper,"%s ",word_Type);
                strcat(start,temper);
                word_Type = strtok(NULL,"+");
            }
            int cleaner =  0;
            // eviter les redondances
            char*temp = malloc(sizeof(char)*100);
            sprintf(temp,"%s",start);
            for(int i =0;i<k;i++){
                if (strcmp(tableau[i],temp) == 0)
                    cleaner = 1;
            }
            if(cleaner == 0){
                sprintf(tableau[k],"%s",temp);
                k++;
            }
        };
        nbr = k;
        for(int v= 0;v<nbr;v++)
            printf("%s",tableau[v]);
    }
    fclose(Dico);
}

/*  -------------------------------------------------------------------------------------------------------------------------------------------------------------  */
// fonction pour extraire tous les mots appartenant à un type donné dans un fichier et retourner une liste
char ** extractWordByType(char* type){
    char * dico = "test.txt";
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        // creer un tableau
        char **tableau = NULL;
        int nbr = 287976; //287976; 10
        tableau = malloc( sizeof(char*) * nbr);
        // allouer une taille à chaque case du tableau
        for (int i=0; i<nbr;i++) {
            tableau[i] = malloc(sizeof(char)*100);
        }
        // extraire les formes de base pour le type
        int k=0;
        while (fgets(buf, sizeof buf, Dico) != NULL){
            char *current_column = strtok(buf, "\t");
            current_column = strtok(NULL, "\t");
            char * temp = malloc(100*sizeof(char));
            sprintf(temp,"%s",current_column);
            current_column = strtok(NULL, "\t");
            strtok(current_column, ":");
            // verifier si le type correspond
            if(strcmp(current_column,type) == 0){
                // verifier si il n'existe pas encore dans le tableau puis ajouter
                //printf("%s\n",temp);
                int clean = 0;
                // eviter les redondances
                for(int i =0;i<k;i++){
                    if (strcmp(tableau[i],temp) == 0)
                        clean = 1;
                }
                if(clean == 0){
                    sprintf(tableau[k],"%s",temp);
                    k++;
                }
            }
            free(temp);
        }
        for(int b=k;b<nbr;b++){
            tableau[k] = NULL;
            free(tableau[k]);
        };
        fclose(Dico);
        return tableau;
    }
};

//fonction pour classer un tableau par ordre alphabétique
char** chainecomp(char** str_ing1){
    int temp1=0;
    char** newtab;
    while(temp1 == 0 ){
        temp1 = 1 ;
        int i = 1 ;
        while(str_ing1[i] != NULL ){
            if(strcmp(str_ing1[i-1],str_ing1[i]) > 0){
                char* temp3 = str_ing1[i-1];
                str_ing1[i-1] = str_ing1[i];
                str_ing1[i] = temp3;
                temp3 = NULL;
                free(temp3);
                temp1 = 0;
            }
            i++;
        }

    }
    return str_ing1 ;
}

//fonction pour generer un nombre en fonction du caractère alphabétique

/*
 * prendre le dictionnaire ✔
 * extraire tous les mots de base pour chaque type ✔
 * les mettre dans un arbre n_air correspondant à leur type
 * choisir un mot au hasard
 * verifier si il à une variante
 * faire le tableau de la variante si oui (lister toute les variantes dans un autre arbre n_air)
 * selectionner une variante pour faire une phrase
 */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
char * char_stripe_last_char(const char ** src){
    int flen = strlen(src[0])-1;

    char dest[flen];
    for(int i =0;i<flen;i++){
        //printf("\n %c \n",src[i]);
        char * desto = &dest[i];
        sprintf(desto,"%c",src[0][i]);
        //dest[i] = src[i];
        //printf("\n %c %d %s\n",dest[i],flen,src[0]);
    }
    //dest[j] = '\0';
    return dest;
}