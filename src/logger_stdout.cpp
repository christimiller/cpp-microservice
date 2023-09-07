#include "logger_stdout.h"
#include "inc/utils.h"

#include <string>
#include <iostream>
#include <utility>

namespace christi {
    LoggerStdout::LoggerStdout() {};

    const std::string LoggerStdout::LoggerStdout::log() const {
        const auto time = christi::Utils::timestamp();

        std::cout << std::endl << time << std::endl;

        return time;
    };

    const std::pair<const std::string, const std::string> LoggerStdout::LoggerStdout::log(const std::string &msg) const {
        const auto time = christi::Utils::timestamp();

        std::cout << std::endl << time << " | " << msg << std::endl;

        return std::pair<const std::string, const std::string> {time, msg};
    };
};
