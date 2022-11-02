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

#endif //SENTENCEGEN_STRUCT_H
