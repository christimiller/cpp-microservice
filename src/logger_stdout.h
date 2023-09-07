#pragma once

#include "inc/logger.h"

#include <string>

namespace christi {
    class LoggerStdout : public Logger {
        public:
            LoggerStdout();
            const std::string log() const;
            const std::pair<const std::string, const std::string> log(const std::string &msg) const;
        private:
    };
};
