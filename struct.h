//
// Created by togla on 02/11/2022.
//

#ifndef SENTENCEGEN_STRUCT_H
#define SENTENCEGEN_STRUCT_H
typedef struct s_form
{
    char *word;
    int tag;
    struct s_form *next;
} t_form, *p_form;

typedef struct s_node
{
    char value;
    struct s_form *forms;
    struct s_child *children;
} t_node, *p_node;

typedef struct s_child
{
    struct s_node *node;
    struct s_child *next;
} t_child, *p_child;

typedef struct s_tree{
    struct s_node * root;
} t_tree,*p_tree;

typedef struct llc{
    int value;
    struct llc * next;
} t_llc , *p_llc ;

// fonctions
p_node create_node(p_node ,char );
p_child create_child(p_child , char );
p_form create_form(p_form ,char * , int);
void fill_form(p_node ,char* ,int , char *);
void display_all_form(p_form );
void display_all_children(p_child );
t_tree create_tree();
#endif //SENTENCEGEN_STRUCT_H
