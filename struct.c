#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
p_form create_form(p_form form,char * mot, int tagbin){
    form = malloc(sizeof(t_form));
    form->word = mot;
    form->tag = tagbin;
    // put other to null
    return form;
};

// remplir / ajouter à un form
void fill_form(p_node  form_start ,char* val,int tagbin,char * type){
    if(form_start->forms == NULL){
        p_form temporary = create_form(temporary,val,tagbin);
        form_start->forms = temporary;
        printf("Created start %s %d %s\n",val,tagbin,type);
    }
    else{
        p_form temp = form_start->forms;
        int found = 0;
        while(temp->next != NULL && found == 0){
            printf("comparing : %d %d %d\n",tagbin,temp->tag,(tagbin == temp->tag));
            if( strcmp(val,temp->word) == 0 && tagbin == temp->tag){
                found = 1;
                printf("Found %s %d %s\n",val,tagbin,type);
            }else{
                temp = temp->next;
            }
        }
        if(found == 0){
            printf("comparing : %d %d %d\n",tagbin,temp->tag,(tagbin == temp->tag));
            if( strcmp(val,temp->word) == 0 && tagbin == temp->tag){
                printf("Found %s %d %s \n",val,tagbin,type);
                found = 1;
            }else{
                temp->next = create_form(temp->next,val,tagbin);
                printf("created for end %s %d %s \n",val,tagbin,type);
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

// afficher tous les mots enfants de l'arbre
void display_all_word_in_tree_by_root(p_node root){
    //verifier si un seul enfant
    // si oui afficher
    // afficher toutes les formes si elles existent
    //sinon verifier autres enfants et les display
    // les afficher si elles existent"
    // afficher toutes les formes si elles existent
}

// creer un arbre
t_tree create_tree(){
  t_tree arbre;
  arbre.root = malloc(sizeof(t_node));
  arbre.root->value = NULL;
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
};

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

void afficher(p_llc my){
    p_llc temp = my;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
};*/
// to del
