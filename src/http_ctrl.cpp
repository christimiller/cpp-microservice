#include "stdafx.h"
#include "http_ctrl.h"
#include "logger_file.h"

christi::LoggerFile logger("./logs/");

namespace christi {
    HttpCtrl::HttpCtrl(string_t url) : m_listener(url) {
        m_listener.support(methods::GET, std::bind(&HttpCtrl::handle_get, this, std::placeholders::_1));
        m_listener.support(methods::PUT, std::bind(&HttpCtrl::handle_put, this, std::placeholders::_1));
        m_listener.support(methods::POST, std::bind(&HttpCtrl::handle_post, this, std::placeholders::_1));
        m_listener.support(methods::DEL, std::bind(&HttpCtrl::handle_delete, this, std::placeholders::_1));
    }

    void HttpCtrl::HttpCtrl::handle_get(http_request message) {
        ucout << message.to_string() << endl;

        logger.log("I am logging GET: url is TODO");

        message.reply(status_codes::OK);
    };

    void HttpCtrl::HttpCtrl::handle_post(http_request message) {
        ucout << message.to_string() << endl;

        logger.log("I am logging POST: url is TODO");

        message.reply(status_codes::OK);
    };

    void HttpCtrl::HttpCtrl::handle_delete(http_request message) {
        ucout << message.to_string() << endl;

        logger.log("DELETE: url is TODO");

        message.reply(status_codes::OK);
    };

    void HttpCtrl::HttpCtrl::handle_put(http_request message) {
        ucout << message.to_string() << endl;

        logger.log("I am logging PUT: url is TODO");

        message.reply(status_codes::OK);
    };
};
