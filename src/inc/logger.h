#pragma once

#include <ostream>
#include <string>

namespace christi {
    class Logger {
    public:
        Logger() = default;
        Logger(const Logger& src) = delete;

        virtual ~Logger() = default;

        virtual const std::string log() const = 0;
    private:
    };
};
