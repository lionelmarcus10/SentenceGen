
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

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
// || option pour checker si le form existe déjà
void fill_form(p_form  form,char* val,int tagbin){
    if(form == NULL){
        form = create_form(form,val,tagbin);
    }
    else{
        p_form temp = form;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = create_form(temp->next,val,tagbin);
    }
};

//afficher tous les form d'un noeud
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
    printf("[ ");
    while(temp!=NULL){
        printf("%c ",temp->node->value);
        temp = temp->next;
    }
    printf("]");
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
/*t_tree create_tree(){
  t_tree arbre;
  arbre.root = malloc(sizeof(t_node));
  arbre.root->value = NULL;
  arbre.root->children = NULL;
  return arbre;
}*/

