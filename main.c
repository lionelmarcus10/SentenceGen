#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void add_Variant_By_Base_In_File(char * base/* type, form llc head*/){

    char * dico = "../dictionnaire_non_accentue.txt";
    int base_Col = 2;
    int variant_Col = 1;
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        int found = 0;
        while (fgets(buf, sizeof buf, Dico) != NULL){
            // recuperer les trois colonnes de la ligne
            char *var_col_element = strtok(buf, "\t");
            char *base_col_element = strtok(NULL,"\t");
            char * prime_part = strtok(NULL,"\t");
            strtok(prime_part,"\n");
            strtok(prime_part,":");
            // recuperer la deuxieme partie de la troisième colonne
            // afficher le variant si la base correspond
            if(strcmp(base, base_col_element) == 0 /* && prime_part == type*/){
                found = 1;
                // get 3 eme col 2eme partie tag
                //fill_form(form_start,base,tag)
                printf("-%s- -%s- -%s- \n",var_col_element,base_col_element,prime_part);
            }
        }
        //to del
        if(found == 0)
            printf("Pas de forme flechis dans le dictionnaire");
        // del
    }
    fclose(Dico);
};

void main(){
    add_Variant_By_Base_In_File("sortir");
    printf("\nHello World!");
}


