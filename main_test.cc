#include <gtest/gtest.h>

#include "prefixes.c"

TEST(PrefixesTest, ShouldAddPrefixToCollectionTest) {
    //given
    initialize_array();
    add(0xC0A8000A, 16);
    add(0x0A000000, 8);
    add(0xC0A80000, 24);
    add(0xC0A80000, 16);
    add(0x0A000000, 8);
    add(0x7B7B7B70, 28);
    add(0xC0A80000, 16);
    add(0x20010DB8, 32);

    //then
    EXPECT_EQ(prefixes.pos, 6);
}


TEST(PrefixesTest, ShouldRemovePrefixFromCollectionTest) {
    //given
    initialize_array();
    add(0xC0A8000A, 16);
    add(0x0A000000, 8);
    add(0xC0A80000, 24);
    add(0xC0A80000, 16);
    add(0x0A000000, 8);
    add(0x7B7B7B70, 28);
    add(0xC0A80000, 16);
    add(0x20010DB8, 32);

    //when
    del(0x0A000000, 8);
    del(0xC0A80000, 16);
    del(0x20010DB8, 1);

    //then
    EXPECT_EQ(prefixes.pos, 4);
}

TEST(PrefixesTest, ShouldCheckAndReturnSmallestMaskGivenPrefixes) {
    //given
    initialize_array();
    add(0xC0000000, 8);
    add(0xC0000000, 16);
    add(0xC0000000, 24);

    //when
    char res = check(0xC00000FF);

    //then
    EXPECT_EQ(res, 24);
}

TEST(PrefixesTest, ShouldNotFindPrefixInCollection) {
    //given
    initialize_array();
    add(0xC0000000, 8);
    add(0xC0000000, 16);
    add(0xC0000000, 24);

    //when
    char res = check(0xCC000000);

    //then
    EXPECT_EQ(res, -1);
}

int main(int argc, char** argv) {
    // Initialize the Google Test framework
    testing::InitGoogleTest(&argc, argv);

    // Run all tests
    return RUN_ALL_TESTS();
}
