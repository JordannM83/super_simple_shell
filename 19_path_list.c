#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct path_node {
    char *dir;
    struct path_node *next;
} path_node;

path_node *build_path_list(char *path)
{
    if (!path)
        return NULL;
    char *copy = strdup(path);
    if (!copy)
        return NULL;
    char *dir = strtok(copy, ":");
    path_node *head = NULL, *tail = NULL;
    while (dir) {
        path_node *node = malloc(sizeof(path_node));
        if (!node) {
            // Free already allocated nodes
            while (head) {
                path_node *tmp = head;
                head = head->next;
                free(tmp->dir);
                free(tmp);
            }
            free(copy);
            return NULL;
        }
        node->dir = strdup(dir);
        node->next = NULL;
        if (!head)
            head = node;
        else
            tail->next = node;
        tail = node;
        dir = strtok(NULL, ":");
    }
    free(copy);
    return head;
}
