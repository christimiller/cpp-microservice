#include <gtest/gtest.h>

#include <utility>
#include <iostream>

#include <fstream>
#include <streambuf>

#include "../src/logger_file.h"

TEST(logger_file_log, LoggerFile) {
    const std::string path = "./logs/";

    christi::LoggerFile loggerFile(path);
    ASSERT_EQ(19, loggerFile.log().length());
};

TEST(logger_file_log_with_path, LoggerFile) {
    const std::string path = "./logs/";

    christi::LoggerFile loggerFile(path);

    const auto log = loggerFile.log();
    
    ASSERT_EQ(19, log.length());
};

TEST(logger_file_log_with_path_and_msg, LoggerFile) {
    const std::string path = "./logs/";
    const std::string msg = "Log test";

    christi::LoggerFile loggerFile(path);

    const auto log = loggerFile.log(msg);

    ASSERT_EQ(19, log.first.length());
    ASSERT_EQ(8, log.second.length());
};

TEST(logger_file_read_msg, LoggerFile) {
    const std::string path = "./logs/";
    const std::string msg = "Log test";

    christi::LoggerFile loggerFile(path);

    const auto log = loggerFile.log(msg);

    const std::string file_name = "./logs/" + log.first + ".log";

    std::ifstream read_file(file_name);

    std::stringstream file_contents;

    file_contents << read_file.rdbuf();

    const std::string compare = "\nDate and Time: " + 
        log.first + 
        " Message: Log test\n";

    ASSERT_EQ(file_contents.str(), compare);
};

