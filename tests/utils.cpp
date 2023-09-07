#include <gtest/gtest.h>

#include "../src/inc/utils.h"

#include <iostream>

TEST(timestamp_length, timestamp) {
    const auto time = christi::Utils::timestamp();

    ASSERT_TRUE(time.length() == 19);
};

TEST(timestamp_formatting, timestamp) {
   const auto time = christi::Utils::timestamp();

   ASSERT_EQ(time.find("-"), 4);
   ASSERT_EQ(time.find(":"), 13);
};
