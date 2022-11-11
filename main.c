#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"

int main(){
    //t_tree Tree = create_tree();
    //extractWordByTypeInDictionnary(Tree.root,"Ver");
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

    display_all_children(Nom_Tree.root->children);
    display_all_children(Pre_Tree.root->children);
    display_all_children(Ver_Tree.root->children);
    display_all_children(Adj_Tree.root->children);
    display_all_children(Int_Tree.root->children);
    display_all_children(Det_Tree.root->children);
    display_all_children(Pro_Tree.root->children);
    display_all_children(Con_Tree.root->children);
    display_all_children(Abr_Tree.root->children);
    display_all_children(Adv_Tree.root->children);
    display_all_children(Ono_Tree.root->children);
    display_all_children(QPro_Tree.root->children);
    display_all_children(Conj_Tree.root->children);

    //add_Variant_By_Base_In_File("stabiliser","Ver");
    //printf("Done \n");
    //display_all_children(Tree.root->children);
    return 0 ;
};
/* call all types
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

display_all_children(Nom_Tree.root->children);
display_all_children(Pre_Tree.root->children);
display_all_children(Ver_Tree.root->children);
display_all_children(Adj_Tree.root->children);
display_all_children(Int_Tree.root->children);
display_all_children(Det_Tree.root->children);
display_all_children(Pro_Tree.root->children);
display_all_children(Con_Tree.root->children);
display_all_children(Abr_Tree.root->children);
display_all_children(Adv_Tree.root->children);
display_all_children(Ono_Tree.root->children);
display_all_children(QPro_Tree.root->children);
display_all_children(Conj_Tree.root->children);
*/
