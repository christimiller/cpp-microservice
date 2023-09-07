#include <gtest/gtest.h>

#include <utility>

#include "../src/logger_stdout.h"

TEST(logger_stdout_log_no_string, LoggerStdout) {
    christi::LoggerStdout loggerStdout;
    ASSERT_EQ(19, loggerStdout.log().length());
};

TEST(logger_stdout_log_with_string, LoggerStdout) {
    const std::string msg = "Log test";

    christi::LoggerStdout loggerStdout;

    const auto log = loggerStdout.log(msg);
   
    ASSERT_EQ(19, log.first.length());
    ASSERT_EQ(8, log.second.length());
};

