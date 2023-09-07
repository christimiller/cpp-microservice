#include "utils.h"

#include <chrono> 
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <utility>

#include <iostream>

namespace christi {
    const std::string Utils::Utils::timestamp() {
        const auto now = std::chrono::system_clock::now();
        const auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream formatted_time;
        formatted_time << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d_%X");
        return formatted_time.str();
    };

    const std::string Utils::Utils::write_file(const std::string &path) {
        const auto date_and_time = timestamp();

        const std::string file_name = path + date_and_time + ".log";

        std::ofstream file;

        file.open (file_name);
        file << "\nDate and Time: " + date_and_time;
        file.close();

        return date_and_time;
    };

    const std::pair<const std::string, const std::string> Utils::Utils::write_file(const std::pair<const std::string, const std::string> &path_and_msg) {
        const auto date_and_time = timestamp();

        const std::string file_name = path_and_msg.first + date_and_time + ".log";

        std::ofstream file;

        file.open (file_name);
        file << "\nDate and Time: " << date_and_time << " Message: " << path_and_msg.second << std::endl;
        file.close();

        return std::pair<const std::string, const std::string>{date_and_time, path_and_msg.second};
    };
};
