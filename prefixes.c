#include "prefixes.h"

void initialize_array() {
    prefixes.list = (prefix*)malloc(PREFIX_LIST_CHUNK_SIZE * sizeof(prefix));
    prefixes.pos = 0;
    prefixes.size = PREFIX_LIST_CHUNK_SIZE;
}

int add(unsigned int base, char mask) {
    if(mask < 0 || mask > 32) {
        return -1;
    }

    if(prefixes.list == NULL) {
        return -1;
    }

    for(int i = 0; i < prefixes.pos; i++) {
        if (prefixes.list[i].base == base && prefixes.list[i].mask == mask) {
            return -1;
        }
    }

    if(prefixes.pos == prefixes.size - 1) {
        printf("Incr prefix array...\n");
        prefixes.list = (prefix*)realloc(prefixes.list, (prefixes.size + PREFIX_LIST_CHUNK_SIZE) * sizeof(prefix));
        if(prefixes.list == NULL) {
            return -1;
        }
        prefixes.size = prefixes.size + PREFIX_LIST_CHUNK_SIZE;
    }

    prefix p;
    p.base = base;
    p.mask = mask;
    prefixes.list[prefixes.pos++] = p;

    return 0;
}

int del(unsigned int base, char mask) {
    if(prefixes.list == NULL) {
        return -1;
    }

    for(int i = 0; i < prefixes.pos; i++) {
        if (prefixes.list[i].base == base && prefixes.list[i].mask == mask) {
            memmove(&prefixes.list[i], &prefixes.list[i+1], (prefixes.pos-i-1) * sizeof(prefix));
            prefixes.pos--;
        }
    }
    return 0;
}

int contains_ip_addr(unsigned int ip, unsigned int base, char mask) {
    unsigned int new_base = base >> (32 - mask);
    unsigned int new_addr = ip >> (32 - mask);
    if (new_addr == new_base) {
        return 1;
    }
    return 0;
}

char check(unsigned int ip) {
    char mask_min = -1;
    for(int i = 0; i < prefixes.pos; i++) {
        unsigned int base = prefixes.list[i].base;
        unsigned int mask = (unsigned int)prefixes.list[i].mask;
        if(contains_ip_addr(ip, base, mask) && (int)mask > (int)mask_min) {
            mask_min = mask;
        }
    }
    return mask_min;
}

void print_prefixes() {
    for(int i = 0; i < prefixes.pos; i++) {
        printf("Prefix %d: %X/%u\n", i, prefixes.list[i].base, prefixes.list[i].mask);
    }
}
