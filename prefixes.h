#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PREFIX_LIST_CHUNK_SIZE 2

typedef struct {
    unsigned int base;
    char mask;
} prefix;

typedef struct {
    prefix *list;
    unsigned int size;
    unsigned int pos;
} prefix_list;

prefix_list prefixes;

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

//int main() {
//    initialize_array();
//
//    if(add(0xC0A8000A, 16) < 0) {
//        return -1;
//    }
//
//    if(add(0x7B7B7B70, 28) < 0) {
//        return -1;
//    }
//
//    print_prefixes();
//
//    printf("%d\n", contains_ip_addr(0x0A010203, 0x0A000000, 8));
//    printf("%d\n", contains_ip_addr(0xC0A80101, 0xC0A80000, 16));
//    printf("%d\n", contains_ip_addr(0xC0A8010A, 0xC0A80100, 24));
//
//    printf("%d\n", contains_ip_addr(0x0B010203, 0x0A000000, 8));
//    printf("%d\n", contains_ip_addr(0xC0B80101, 0xC0A80000, 16));
//    printf("%d\n", contains_ip_addr(0x20010DB9, 0x20010DB8, 32));
//
//    if(del(0xC0A8000A, 16))
//
//    //print list after deletion
//    printf("\nafter:\n");
//
//    for(int i = 0; i < prefixes.size; i++) {
//        printf("Prefix %d: %X/%u\n", i, prefixes.list[i].base, prefixes.list[i].mask);
//    }
//
//    //cleanup
//    if(prefixes.list != NULL) {
//        free(prefixes.list);
//    }
//
//    return 0;
//}
