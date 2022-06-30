#include "util/PrettyPrinters.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include <iostream>
#include <pqxx/pqxx>
#include <vector>

int main() {
    // spdlog
    spdlog::info("Sample Info output");
    spdlog::warn("Sample Warn output");
    spdlog::error("Sample Error output");

    auto filelog = spdlog::basic_logger_mt("sample-logger", "sample-log.txt");

    filelog.get()->info("Sample Info output.");
    filelog.get()->warn("Sample Warn output.");
    filelog.get()->error("Sample Error output.");

    // pqxx
    try {
        pqxx::connection C("dbname = books user = sap password = kentjw \
                               hostaddr = 127.0.0.1");
        if (C.is_open()) {
            std::cout << "Opened database successfully: " << C.dbname() << std::endl;
        }
        else {
            std::cout << "Can't open database" << std::endl;
            return 1;
        }
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}