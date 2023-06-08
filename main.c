#include "prefixes.h"


int run_test(char *testName, int (*testFunc)()) {
    int testRes = (*testFunc)();
    if(testRes != 0) {
        printf("\nERROR\n%s returned unexpected value\n\n", testName);
    } else {
        printf("[OK] %s\n", testName);
    }
    return testRes;
}

int ShouldAddPrefixToCollectionTest() {
    //given
    initialize_tree();
    add(0x0A000000, 8);
    add(0x0A000000, 8);

    add(0xC0A80000, 16);
    add(0xC0A80000, 16);

    add(0xC0A80000, 24);
    add(0xC0A80000, 28);
    add(0x7B7B7B70, 28);
    add(0x20010DB8, 32);

    //then
    if(prefixes.size == 6) {
        return 0;
    }
    else {
        return -1;
    }
}


int ShouldRemovePrefixFromCollectionTest() {
    //given
    initialize_tree();
    add(0xC0A8000A, 16);
    add(0x0A000000, 8);
    add(0xC0A80000, 24);
    add(0x7B7B7B70, 28);
    add(0x20010DB8, 32);

    //when
    del(0x0A000000, 8);
    del(0xC0A80000, 16);
    del(0x20010DB8, 1);
    del(0x20010DB8, 31);

    //then
    if(prefixes.size == 3) {
        return 0;
    }
    else {
        return -1;
    }
}

int ShouldCheckAndReturnSmallestMaskGivenPrefixes() {
    //given
    initialize_tree();
    add(0xC0000000, 8);
    add(0xC0000000, 16);
    add(0xC0000000, 24);

    //when
    char res = check(0xC00000FF);

    //then
    if(res == 24) {
        return 0;
    }
    else {
        return -1;
    }
}

int ShouldNotFindPrefixInCollection() {
    //given
    initialize_tree();
    add(0xC0000000, 8);
    add(0xC0000000, 16);
    add(0xC0000000, 24);

    //when
    char res = check(0xCC000000);

    //then
    if(res == -1) {
        return 0;
    }
    else {
        return -1;
    }
}

int main() {

    int res = run_test("ShouldAddPrefixToCollectionTest", &ShouldAddPrefixToCollectionTest)
            + run_test("ShouldRemovePrefixFromCollectionTest", &ShouldRemovePrefixFromCollectionTest)
            + run_test("ShouldCheckAndReturnSmallestMaskGivenPrefixes", &ShouldCheckAndReturnSmallestMaskGivenPrefixes)
            + run_test("ShouldNotFindPrefixInCollection", &ShouldNotFindPrefixInCollection);

    return res;

}
