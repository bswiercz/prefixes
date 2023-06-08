#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PREFIX_LIST_CHUNK_SIZE 2
#define PREFIX_MAX 32

typedef struct {
    struct prefix_item *l;
    struct prefix_item *r;
    char has_mask;
} prefix_item;

typedef struct {
    prefix_item *root;
    char size;
} prefix_tree;

extern prefix_tree prefixes;

void initialize_tree();
prefix_item *init_branch();

/**
 * initializes array
 */
void initialize_array();

/**
 * adds prefix to collection
 * @param base base of newly added prefix
 * @param mask mask of newly added prefix
 * @return 0 = success, -1 = bad request
 */
int add(unsigned int base, char mask);

/**
 * deletes prefix from collection
 * @param base base of prefix
 * @param mask mask of prefix
 * @return 0 = ok\n-1 = bad argument
 */
int del(unsigned int base, char mask);

/**
 * check if prefix contains ip address
 * @param ip ip address to check
 * @param base base od prefix
 * @param mask mask of prefix
 * @return 1 = contains\n0 = does not contain
 */
int contains_ip_addr(unsigned int ip, unsigned int base, char mask);

/**
 * checks if ip address belongs to any prefix in collection
 * @param ip ip address to check
 * @return smallest mask of prefix which includes ip address
 */
char check(unsigned int ip);
