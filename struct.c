#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//create node
p_node create_node(p_node node ,char val){
    node = malloc(sizeof(t_node));
    node->value = val;
    // put other to null
    node->children = NULL;
    node->forms = NULL;
    return node;
};

// create child
p_child create_child(p_child child, char val){
    child = malloc(sizeof(t_child));
    child->node = create_node(child->node,val);
    // put other to null

    child->next = NULL;
    return child;
};

// create form
p_form create_form(char * mot, int tagbin){
    p_form form;
    form = malloc(sizeof(t_form));
    form->word = mot;
    form->tag = tagbin;
    form->next = NULL;
    // put other to null
    return form;
};

// remplir / ajouter à un form
void fill_form(p_node form_start ,char* val,int tagbin,char * type){
    if(form_start->forms == NULL){
        p_form temporary = create_form(val,tagbin);
        form_start->forms = temporary;

        //printf("Created from start %s %d %s\n",val,tagbin,type);
    }
    else{
        p_form temp = form_start->forms;
        //printf("--%s\n",temp->word);
        int found = 0;
        // comparer la première valeur
        //printf("comparing : %s %s %d\n",val,temp->word,(strcmp(val,temp->word)));
        if(strcmp(val,temp->word) == 0 && tagbin == temp->tag){
            found = 1;
            //printf("Found1 %s %d %s\n",val,tagbin,type);
        }
        // comparer la deuxième valeur jusqu'a l'avant dernière
        while(temp->next != NULL && found == 0){
            //printf("comparing : %d %d %d\n",tagbin,temp->tag,(tagbin == temp->tag));
            if( strcmp(val,temp->word) == 0 && tagbin == temp->tag){
                found = 1;
                //printf("Found2 %s %d %s\n",val,tagbin,type);
            }else{
                temp = temp->next;
            }
        }
        // comparer la dernière valeur
        if(found == 0){
            //printf("comparing : %d %d %d\n",tagbin,temp->tag,(tagbin == temp->tag));
            if( strcmp(val,temp->word) == 0 && tagbin == temp->tag){
                //printf("Found3 %s %d %s \n",val,tagbin,type);
                found = 1;
            }else{
                temp->next = create_form(/*temp->next,*/val,tagbin);
                //printf("created for end %s %d %s \n",val,tagbin,type);
            }
        }
    }
};

//afficher tous les form d'un noeud final
void display_all_form(p_form form){
    p_form temp = form;
    printf("\n[ ");
    while(temp!=NULL){
        printf(" %s ",temp->word);
        temp = temp->next;
    }
    printf("]\n");
};

int count_children(p_child child){
    p_child temp = child;
    int cpt = 0;
    while(temp!=NULL){
        cpt++;
        temp = temp->next;
    }
    return cpt;
}

//afficher tous les enfants enfant d'un noeud
void display_all_children(p_child child){
    p_child temp = child;
    printf("\n[ ");
    while(temp!=NULL){
        printf("%c ",temp->node->value);
        temp = temp->next;
    }
    printf("]\n");
};

// a modifier
void extraire_un_mot_aleatoirement(p_node root){

    //srand(time(NULL));
    p_child temp_child = root->children;
    char full[27] = "";
    while(count_children(temp_child) != 0 ){
        //display_all_children(temp_child);
        int max = count_children(temp_child);

        int x = rand() % max;
        int i = 0;
        while(i<x){
            temp_child = temp_child->next;
            i++;
        }
        strncat(full,&temp_child->node->value,1);
        temp_child = temp_child->node->children;
    }
    printf("\nLe mot genere aleatoirement est : %s\n\n",full,strlen(full));
}

char * random_word_string(p_node root){

    //srand(time(0));
    p_child temp_child = root->children;
    char full[27] = "";
    while(count_children(temp_child) != 0 ){
        int max = count_children(temp_child);
        int x = rand() % max;
        int i = 0;
        while(i<x){
            temp_child = temp_child->next;
            i++;
        }
        strncat(full,&temp_child->node->value,1);
        temp_child = temp_child->node->children;
    }
    char * full2 = malloc(sizeof(char)*27);
    sprintf(full2,"%s",full);
    return full2;
}

//generer une phrase
void generate_sentence(int choice,p_node root_Nom,p_node root_Pre, p_node root_Ver, p_node root_Adj, p_node root_Int,
                       p_node root_Det, p_node root_Pro,p_node root_Con,p_node root_Abr,p_node root_Adv,
                       p_node root_Ono,p_node root_QPro,p_node root_Conj){
    switch (choice) {
        case 1:{
            char * Name = random_word_string(root_Nom);
            char * Verbe = random_word_string(root_Ver);
            char * Name2 = random_word_string(root_Nom);
            char * Adjectif = random_word_string(root_Adj);
            printf("La phrase genere est  : \n");
            printf("\n%s %s %s %s\n\n",Name,Adjectif,Verbe,Name2);
            break;
        }
        case 2:{
            char * Name = random_word_string(root_Nom);
            char * Verbe = random_word_string(root_Ver);
            char * Name2 = random_word_string(root_Nom);
            char * Adjectif = random_word_string(root_Adj);
            printf("La phrase genere est  : \n");
            printf("\n%s qui %s %s %s \n\n",Name,Verbe,Name2,Adjectif);
        }
        default:
            break;
    }
};

// afficher tous les mots enfants de l'arbre
void display_all_word_in_tree_by_root(p_node root){
    p_node temp = root;
    if(temp->value != NULL){
        if(temp->children == NULL){
            printf("%c",temp->value);
        }else{
            p_child child_temp = temp->children;
            if(child_temp != NULL){
                printf("%c",child_temp->node->value);
                display_all_word_in_tree_by_root(child_temp->node);
            }
            if(child_temp->next != NULL){
                child_temp = child_temp->next;
                display_all_word_in_tree_by_root(child_temp->node);
            }
        }
    }else{
        printf("Vide");
    }
}

// creer un arbre
t_tree create_tree(){
  t_tree arbre;
  arbre.root = malloc(sizeof(t_node));
  arbre.root->value = " ";
  arbre.root->children = NULL;
  return arbre;
}


/*
// creer une llc;

p_llc create(p_llc myllc,int val){
    myllc = malloc(sizeof(t_llc));
    myllc->value = val;
    //myllc->next = NULL;
    return myllc;
};*/
/*

void remplir(p_llc * my,int val){
    if(*my == NULL){
        *my = create(my,val);
    }
    else{
        p_llc temp = *my;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = create(temp->next,val);
    }

};
*/
/*
void afficher(p_llc my){
    p_llc temp = my;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
};*/
// to del
