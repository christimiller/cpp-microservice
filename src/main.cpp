#include "stdafx.h"
#include "http_ctrl.h"

std::unique_ptr<christi::HttpCtrl> g_httpCtrl;

void on_initialize(const string_t& address) {
    uri_builder uri(address);
    uri.append_path(U("health"));

    auto addr = uri.to_uri().to_string();
    g_httpCtrl = std::unique_ptr<christi::HttpCtrl>(new christi::HttpCtrl(addr));
    g_httpCtrl->open().wait();

    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

    return;
}

void on_shutdown() {
    g_httpCtrl->close().wait();
    return;
}

int main(int argc, char* argv[]) {
    string_t address = U("http://0.0.0.0:");
    if (const char* env_p = std::getenv("APIPORT")) {
        address.append(env_p);
    } else {
        if (argc == 2) {
            address.append(argv[1]);
        }
    }

    on_initialize(address);
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    on_shutdown();
    return 0;
}
