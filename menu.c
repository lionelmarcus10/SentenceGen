//
// Created by togla on 14/11/2022.
//

#include "menu.h"
#include  "file.h"
#include <stdio.h>
#include <time.h>
#include "stdlib.h"
#include "string.h"
#include "file.h"
#define Yes 1
#define No 0
void menu_principal(){

    // initialisation et creation des arbres
    t_tree Nom_Tree = create_tree();
    t_tree Pre_Tree = create_tree();
    t_tree Ver_Tree = create_tree();
    t_tree Adj_Tree = create_tree();
    t_tree Int_Tree = create_tree();
    t_tree Det_Tree = create_tree();
    t_tree Pro_Tree = create_tree();
    t_tree Con_Tree = create_tree();
    t_tree Abr_Tree = create_tree();
    t_tree Adv_Tree = create_tree();
    t_tree Ono_Tree = create_tree();
    t_tree QPro_Tree = create_tree();
    t_tree Conj_Tree = create_tree();

    extractWordByTypeInDictionnary(Nom_Tree.root,"Nom");
    extractWordByTypeInDictionnary(Pre_Tree.root,"Pre");
    extractWordByTypeInDictionnary(Ver_Tree.root,"Ver");
    extractWordByTypeInDictionnary(Adj_Tree.root,"Adj");
    extractWordByTypeInDictionnary(Int_Tree.root,"Int");
    extractWordByTypeInDictionnary(Det_Tree.root,"Det");
    extractWordByTypeInDictionnary(Pro_Tree.root,"Pro");
    extractWordByTypeInDictionnary(Con_Tree.root,"Con");
    extractWordByTypeInDictionnary(Abr_Tree.root,"Abr");
    extractWordByTypeInDictionnary(Adv_Tree.root,"Adv");
    extractWordByTypeInDictionnary(Ono_Tree.root,"Ono");
    extractWordByTypeInDictionnary(QPro_Tree.root,"QPro");
    extractWordByTypeInDictionnary(Conj_Tree.root,"Conj");

    // fin initialisation et creation
    int B,x;
    printf("\t\t\t\t\t Bienvenue dans notre generateur de phrase \n ");
    while(1){
        B=7;
        int W;
        do {
            printf("Veuillez taper un numero\n");
            printf("1- Se documenter sur un mot de base\n");
            printf("2- Extraire un mot au hasard\n");
            printf("3- Generer une phrase\n");
            printf("4- Essayez notre algorithme de complmetion automatique\n");
            printf("5- Rechercher un mot peu import qu'il soit une forme fléchis ou une forme de base\n");
            printf("6-  Veuillez taper 6 pour quitter le programme \n");
            printf("Saissez un numero :  ");
            scanf("%d", &B);
            if (B != 1) {
                fflush(stdin);
            }
        }while(B != 1 && B != 2 && B != 3 && B != 4 && B!= 5 && B!= 6);

        switch(B){
            case 1 :
                rechercher_global_by_base(Nom_Tree.root ,Pre_Tree.root, Ver_Tree.root, Adj_Tree.root, Int_Tree.root,
                                          Det_Tree.root, Pro_Tree.root,Con_Tree.root,Abr_Tree.root,Adv_Tree.root,
                                          Ono_Tree.root,QPro_Tree.root,Conj_Tree.root);

                break;
            case 2 :
                extraire_un_mot_aleatoirement(Nom_Tree.root);
                break;
            case 3 : {
                printf("\nNous vous proposons plusieures types de phrases \n");
                do {

                    printf("Veuillez taper le numero \n");
                    printf("1- Nom - adjectif - verbe - Nom\n2- Nom - 'qui' - verbe - Nom -adjectif\n3- Interjection - Nom  - verbe - adjectif\n4- Nom - verbe - adverbe - adjectif\n5- Preposition - Nom - Preposition - Nom\n6- Pronoms  - Nom - Preposition - verbe\nSaisissez un numero :");
                    scanf("%d", &x);
                    printf("%d", x);
                    if (x != 1) {
                        fflush(stdin);
                    }
                    printf("\n");
                } while (x != 1 && x != 2 && x != 3 && x != 4 && x != 5 && x != 6 && x != 7 && x != 8 && x != 9);
                generate_sentence(x, Nom_Tree.root, Pre_Tree.root, Ver_Tree.root, Adj_Tree.root, Int_Tree.root,
                                  Det_Tree.root, Pro_Tree.root, Con_Tree.root, Abr_Tree.root, Adv_Tree.root,
                                  Ono_Tree.root, QPro_Tree.root, Conj_Tree.root);
                break;
            }
            case 4:{
                int check = 0;
                while(check == 0){
                    printf("Veuillez saisir un mot");
                    char * mot = malloc(24*sizeof(char ));
                    mot= mot_a_chercher();
                    p_child temp2 = Nom_Tree.root->children;
                    p_node myroot = Nom_Tree.root;
                    int x = strlen(mot);
                    int i = 0;
                    for(i;i<x;i++){
                        temp2 = chercher_un_enfant(myroot,mot[i]);
                        myroot = temp2->node;
                    }
                    check = beta_completion(myroot);
                }
                break;
            }
            case 5 :
                    break;
            case 6 :
                printf(".......................Au revoir.......................");
                B = 6;
                return;
        }


    }

}