#pragma once

#include "inc/logger.h"

#include <string>
#include <utility>

namespace christi {
    class LoggerFile : public Logger {
        public:
            LoggerFile();
            LoggerFile(const std::string &path);
            const std::string log() const;
            const std::pair<const std::string, const std::string> 
                log(const std::string &msg) const;
        private:
            std::string path;
    };
};
