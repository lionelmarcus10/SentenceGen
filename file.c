//
// Created by Lionel on 27/10/2022.
//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"


//- fonction pour trouver la base d'un mot à partir de la forme fléchis et afficher ( fonction utilisé en interne )
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

// fonction pour afficher la nature des mots sur chaque colonne : uniq values ( fonction utilisé en interne pour connaitre toutes les natures de mot)
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

// fonction pour afficher les differents types de conjugaison des mots sur chauque colonne : uniq values ( fonction utilisé en interne pour connaitre les differents temps et accords utilisés )
void thirColFirstParser2Show(){
    int column = 3;
    char * dico = "../dictionnaire_non_accentue.txt";
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

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------  */
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


// creer et chercher un enfants sur la ligne horizontale
p_child child_horizontal(char val,p_node rac){
    // si le noeud est null
    if(rac->children == NULL){
        p_child temp_null = create_child(temp_null,val);
        rac->children = temp_null;
        return temp_null;
    }else{
        p_child temp_child = rac->children;

        // comparer le premier enfant
        if(temp_child->node->value == val){
            return temp_child;
        }else{
            // comparer les autres enfants
            while(temp_child->next != NULL){
                if(temp_child->node->value == val)
                    return temp_child;
                else
                    temp_child = temp_child->next;
            }
            // comparer le dernier enfant
            if(temp_child->node->value == val)
                return temp_child;
            else{
                // creer un enfant après le dernier enfant ( add a tail)
                temp_child->next = create_child(temp_child->next,val);
                temp_child = temp_child->next;
                return temp_child;
            }
            // to modify
        }
    }
};

// ajouter les formes fléchis à la fin du mot d'une forme de base
void add_Variant_By_Base_In_File(char * base, char * typeName, p_node form_start){
    char * dico = "../dictionnaire_non_accentue.txt";
    //char * dico = "../test.txt";
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        int found = 0;
        char * tag_tab = malloc(85*sizeof(char));
        char * secondInt = malloc(85*sizeof(char));
        while (fgets(buf, sizeof buf, Dico) != NULL){
            // recuperer les trois colonnes de la ligne
            char *var_col_element = strtok(buf, "\t");
            char *base_col_element = strtok(NULL,"\t");
            if(strcmp(base, base_col_element) == 0){
                char * second_part = strtok(NULL,"\t");
                strtok(second_part,"\n");
                sprintf(secondInt,"%s",second_part);
                char * first_part = strtok(secondInt,":");

                if(strcmp(first_part,typeName) ==0 ){
                    strtok(second_part,":");
                    if(invariable(typeName) == 1){
                        //printf("%s %s %s\n",typeName,var_col_element,base_col_element);
                        fill_form(form_start,var_col_element,0,typeName);
                        //display_all_form(form_start->forms);
                    }
                    while(second_part !=NULL){
                        second_part = strtok(NULL,":");
                        if(second_part != NULL){
                            sprintf(tag_tab,"%s",second_part);
                            int tag = getFlags(tag_tab);
                            fill_form(form_start,var_col_element,tag,typeName);
                            //display_all_form(form_start->forms);
                        }
                    }
                }

            }
        };
        free(tag_tab);
    }
    fclose(Dico);
};

// remplir children en vertical
void remplir_arbre(p_node racine ,char * mot,char * typeName){
    int length = strlen(mot);
    // si le noeud RACINE n'a pas d'enfant
    p_child temp;
    if(racine->children == NULL){
        racine->children = create_child(racine->children,mot[0]);
        temp = racine->children;
        for(int i =1;i<length-1;i++){
            p_child temp2 = create_child(temp2,mot[i]);
            temp->node->children = temp2;
            temp = temp->node->children;
        };
        p_child temp2 = create_child(temp2,mot[length-1]);
        // remplir la dernière case et toutes les formes
        temp = temp2;

    }else{
        p_node temp_node = racine;
        temp = racine->children;
        for(int x =0;x<length-1;x++){
            temp = child_horizontal(mot[x],temp_node);
            temp_node = temp->node;
        };
        // remplir la dernière case et toutes les formes
        temp = child_horizontal(mot[length-1],temp_node);
        temp_node  = temp->node;
    }
    // remplir la form si elle est null
    if(temp->node->forms == NULL){
        //printf(" %s",mot);
        //add_Variant_By_Base_In_File(mot, typeName,temp->node);
        //display_all_form(temp->node->forms);
        //printf("lol\n");
    }
}


// Remplir un type d'arbre
t_tree extractWordByTypeInDictionnary(p_node racine ,char * typeOfTree){

    char * dico = "../dictionnaire_non_accentue.txt";
    //char * dico = "../test.txt";
    FILE * Dico = fopen(dico,"r");
    if(!Dico) {
        perror("File opening failed");
    }else{
        char buf[200];
        // extraire les infos de chaque ligne
        int k=0;
        // creer un tableau de sting
        char **tableau = NULL;
        tableau = malloc( sizeof(char*) *3);
        // allouer une taille à chaque case du tableau
        for (int i=0; i<3;i++) {
            tableau[i] = malloc(sizeof(char)*85);
        }
        while (fgets(buf, sizeof buf, Dico) != NULL){

            // use  t-0, t-1, thirdCol
            // colonne 1
            char *current_column = strtok(buf, "\t");
            sprintf(tableau[0],"%s",current_column);

            // colonne 2
            // supprimer le \t collé aux mots
            current_column = strtok(NULL, "\t");
            sprintf(tableau[1],"%s",current_column);

            // colonne 3
            current_column = strtok(NULL, "\n");
            char* thirdCol = malloc((strlen(current_column))*sizeof(char));
            sprintf(thirdCol,"%s",strtok(current_column, "\n"));
            char* typePart = strtok(thirdCol,":");

            // verifier si les types correspondent
            if(strcmp(typeOfTree,typePart) == 0){
                // remplir l'arbre
                //printf("-%s-",tableau[1]);
                remplir_arbre(racine,tableau[1],typeOfTree);
                //printf("\n");
            }

        }
        // fin while

    }
    fclose(Dico);
};

// fonction pour reperer les types invariable
int invariable(char * type){
    char str_type[] = "Pre Adv Ono Abr Conj QPro Int Con";
    if(strstr(str_type,type) == NULL)
        return 0;
    return 1;
};


/*------------------------------------------------------------------------------------*/
// une fonction pour trouver un enfant
p_child chercher_un_enfant(p_node p, char c){
    p_child temporary_child = p->children;
    p_child temp = NULL;
    while(temporary_child->next != NULL){
        if(temporary_child->node->value == c )
            return temporary_child;
        else
            temporary_child = temporary_child->next;
    }
    if(temporary_child->node->value == c )
        return temporary_child;
    else
        return temp;
}

// une fonction pour permet de saisir un mot à chercher
char* mot_a_chercher(){
    char * mot = malloc(27 * sizeof(char)) ;
    printf("Veuillez saisir le mot que vous voulez chercher : ");
    scanf("%s",mot);
    return mot ;
}

// une fonction pour rechercher un mot
void  rechercher_un_mot(p_node root, char* type, char* mot  ){

    int length = strlen(mot);
    p_node pn = root;

    if( pn->children == NULL){
        printf(" N'exste pas dans : %s\n",type);
    }else {

        if (pn->children != NULL) {
            pn = root;
            /* for (int i = 0; i < length; i++) */

            int i = 0;
            while (i < length && pn !=NULL){
                if(pn->children == NULL){
                    printf(" N'existe pas dans : %s\n", type);
                    pn= NULL;
                }else{
                    p_child b = chercher_un_enfant(pn, mot[i]);

                    if (b != NULL) {
                        pn = b->node;
                    } else {
                        //Le mot n'exite pas
                        printf(" N'existe pas dans : %s\n", type);
                        pn = NULL;
                    }
                }
                i++;
            }
            if (pn != NULL) {

                printf("\n Le mot saisie : %s est une forme de base de nature => %s \n",mot, type);

                // appeler la fonction pour lire les forme flèchie de la fin de mot et leur si-facation
            }
        }


    }
}

void  rechercher_global_by_base(p_node root_Nom,p_node root_Pre, p_node root_Ver, p_node root_Adj, p_node root_Int,
                                p_node root_Det, p_node root_Pro,p_node root_Con,p_node root_Abr,p_node root_Adv,
                                p_node root_Ono,p_node root_QPro,p_node root_Conj)

{
    char * mot = malloc(24*sizeof(char ));
    mot= mot_a_chercher();
    printf("\n\n%s\n\n",mot);
    rechercher_un_mot(root_Nom,Nom,mot);
    rechercher_un_mot(root_Pre,Pre,mot);
    rechercher_un_mot(root_Ver, Ver,mot);
    rechercher_un_mot(root_Adj, Adj,mot);
    rechercher_un_mot(root_Int, Int,mot);
    rechercher_un_mot(root_Det, Det,mot);
    rechercher_un_mot(root_Pro,Pro,mot);
    rechercher_un_mot(root_Con, Con,mot);
    rechercher_un_mot(root_Abr, Abr,mot);
    rechercher_un_mot(root_Adv,Adv,mot);
    rechercher_un_mot(root_Ono, Ono,mot);
    rechercher_un_mot(root_QPro, QPro,mot);
    rechercher_un_mot(root_Conj, Conj,mot);

}

