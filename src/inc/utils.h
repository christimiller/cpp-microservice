#pragma once

#include <string>
#include <utility>

namespace christi {
    class Utils {
    public:
        const static std::string timestamp();

        const static std::string write_file(const std::string &path);
        const static std::pair<const std::string, const std::string> write_file(const std::pair<const std::string, const std::string> &path_and_msg);
    };
};
