#include "prefixes.h"

prefix_tree prefixes;

void initialize_tree() {
    prefixes.root = init_branch();
    prefixes.size = 0;
}

prefix_item *init_branch() {
    prefix_item *item = (prefix_item*)malloc(sizeof(prefix_item));
    item->l = NULL;
    item->r = NULL;
    item->has_mask = 0;
    return item;
}

int add(unsigned int base, char mask) {
    if(mask < 0 || mask > 32) {
        return -1;
    }

    if(prefixes.root == NULL) {
        return -1;
    }

    prefix_item *ptr = prefixes.root;

    for(int i = 0; i < mask; i++) {
        char dir = 0x1 & ( base >> (PREFIX_MAX - i - 1) );
        if(dir == 0) {
            if(ptr->l == NULL) {
                ptr->l = init_branch();
            }
            ptr = ptr->l;
        }
        else if(dir == 1) {
            if(ptr->r == NULL) {
                ptr->r = init_branch();
            }
            ptr = ptr->r;
        }
    }

    if(ptr->has_mask == 0) {
        ptr->has_mask = 1;
        prefixes.size++;
    }

    return 0;
}

int del(unsigned int base, char mask) {
    if(prefixes.root == NULL) {
        return -1;
    }

    prefix_item *ptr = prefixes.root;

    for(int i = 0; i < mask; i++) {
        char dir = 0x1 & ( base >> (PREFIX_MAX - i - 1) );
        if(dir == 0) {
            if(ptr->l == NULL) {
                return -1;
            }
            ptr = ptr->l;
        }
        else if(dir == 1) {
            if(ptr->r == NULL) {
                return -1;
            }
            ptr = ptr->r;
        }
    }

    if(ptr->has_mask == 1) {
        ptr->has_mask = 0;
        prefixes.size--;
    }

    return 0;
}

