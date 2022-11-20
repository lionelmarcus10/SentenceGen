#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "tag.h"
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
// essayer avec un p_form puis un p_form *
void fill_form(p_node form_start ,char* val,int tagbin,char * type){
    if(form_start->forms == NULL){
        form_start->forms = create_form(val,tagbin);
        //printf("Created from start %s %d %s\n",val,tagbin,type);
    }
    else{
        //printf("Created from end %s %d %s\n",val,tagbin,type);
        p_form temp = form_start->forms;
        while(temp->next != NULL){
            temp = temp->next;
        }
        // put into the queue
        temp->next = create_form(val,tagbin);
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

    srand(time(NULL)*getpid());
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

    srand(time(NULL)*getpid());
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
            break;
        }
        case 3:{
            char * Interjection = random_word_string(root_Int);
            p_form Name = world_base_in_forms(root_Nom);
            p_form Adjectif = search_in_forms(root_Adj,Name->tag);
            // generer le verbe en fonction du nom
            // afficher la phrase
            printf("%s %s %s",Interjection,Name,Adjectif);
            break;
        }
        case 4:{
            char * Adverbe = random_word_string(root_Adv);
            p_form Name = world_base_in_forms(root_Nom);
            p_form Adjectif = search_in_forms(root_Adj,Name->tag);
            // generer le verbe en fonction du nom
            // afficher la phrase
            break;
        }
        case 5:{
            char * Preposition1 = random_word_string(root_Pre);
            char * Name1 = random_word_string(root_Nom);
            char * Preposition2 = random_word_string(root_Pre);
            char * Name2 = random_word_string(root_Nom);
            printf("\n%s %s %s %s\n\n",Preposition1, Name1, Preposition2,Name2);
            break;
        }
        case 6:{
            char * Preposition = random_word_string(root_Pre);
            p_form Pronom = world_base_in_forms(root_Pro);
            char * Name = random_word_string(root_Nom);
            //p_form Name = search_in_forms(root_Nom,Pronom->tag);
            printf("\n%s %s %s\n\n",Pronom->word,Preposition,Name);
            break;
        }
        default:
            break;
    }
};

// generate base word and return his form structure
p_form world_base_in_forms(p_node root){

    srand(time(NULL)*getpid());
    p_child temp_child = root->children;
    char full[27] = "";
    p_form temp_form;
    while(count_children(temp_child) != 0 ){
        int max = count_children(temp_child);
        int x = rand() % max;
        int i = 0;
        while(i<x){
            temp_child = temp_child->next;
            i++;
        }
        strncat(full,&temp_child->node->value,1);
        temp_form = temp_child->node->forms;
        temp_child = temp_child->node->children;
    }
    // recuperer le pointeur sur sa forme
    while( strcmp(temp_form->word,full) != 0 ){
      temp_form = temp_form->next;
    }
    return temp_form;

}

// rechercher (generer) une forme flechis correspondante (verbe, nom, adj) en faisant l'accord
p_form search_in_forms(p_node root,int tag ){
    // generer un mot de base
    srand(time(NULL)*getpid());
    p_child temp_child = root->children;
    char full[27] = "";
    p_form temp_form;
    while(count_children(temp_child) != 0 ){
        int max = count_children(temp_child);
        int x = rand() % max;
        int i = 0;
        while(i<x){
            temp_child = temp_child->next;
            i++;
        }
        strncat(full,&temp_child->node->value,1);
        temp_form = temp_child->node->forms;
        temp_child = temp_child->node->children;
    }
    // recuperer le pointeur sur sa forme
    // temp_form->tag
     // operation uniquement pour les verbes
     int found =0;
     while(found !=1){
         if(verification_tag(tag,temp_form->tag) == 1){
             return temp_form;
         }else{
             temp_form = temp_form->next;
         }
     }
     return temp_form;
}

// comparer les tag sauf pour les verbes ( cas special )
int verification_tag(int tag1, int tag2){
    // si le tag1 correspond avec le tag 2
      if(tag1 == tag2){
          return 1;
      }else{
            // mas sg
            if( ( (tag1 & (Mas_TB+SG_TB) ) == (Mas_TB+SG_TB) ) &&  ( tag2 & (InvGen_TB+SG_TB) == (InvGen_TB+SG_TB) || tag2 & (Mas_TB+InvPL_TB) == (Mas_TB+InvPL_TB)  )  ){
                return 1;
            }
            // mas pl
            else if( ( (tag1 & (Mas_TB+PL_TB) ) == (Mas_TB+PL_TB) ) &&  ( tag2 & (InvGen_TB+PL_TB) == (InvGen_TB+PL_TB) || tag2 & (Mas_TB+InvPL_TB) == (Mas_TB+InvPL_TB) )  ){
                return 1;
            }
            // fem sg
            else if( ( (tag1 & (Fem_TB+SG_TB) ) == (Fem_TB+SG_TB) ) &&  ( tag2 & (InvGen_TB+SG_TB) == (InvGen_TB+SG_TB) || tag2 & (Fem_TB+InvPL_TB) == (Fem_TB+InvPL_TB) )  ){
                return 1;
            }
            // fem pl
            else if( ( (tag1 & (Fem_TB+PL_TB) ) == (Fem_TB+PL_TB) ) &&  ( tag2 & (InvGen_TB+PL_TB) == (InvGen_TB+PL_TB) || tag2 & (Fem_TB+InvPL_TB) == (Fem_TB+InvPL_TB) )  ){
                return 1;
            }
            // inv sg
            else if( ( (tag1 & (InvGen_TB+SG_TB) ) == (InvGen_TB+SG_TB) ) &&  ( tag2 & (SG_TB) == (SG_TB) )  ){
                return 1;
            }
            // inv pl
            else if( ( (tag1 & (InvGen_TB+PL_TB) ) == (InvGen_TB+PL_TB) ) &&  ( tag2 & (PL_TB) == (PL_TB) )  ){
                return 1;
            }
            // ingen + inv pl
            else if( (tag1 & (InvGen_TB+InvPL_TB) ) == (InvGen_TB+InvPL_TB) ){
                return 1;
            }
            else if( ( (tag1 & (InvPL_TB+Mas_TB) ) == (InvPL_TB+Mas_TB) ) && (tag2 & (Mas_TB)) == Mas_TB ){
                return 1;
            }else if( ( (tag1 & (InvPL_TB+Fem_TB) ) == (InvPL_TB+Fem_TB) ) && (tag2 & (Fem_TB)) == Fem_TB ){
                return 1;
            }
      }
      return 0;
}

// conjugaison
void conjugaison(){
    // prendre la structure du mot (form struct)

    // generer et rechercher un mot correspondant à son tag dans les flechis

    // retourner ce mot
}


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
