#pragma once
#include <string>
#include <vector>

class Parser {
    public:
        // Default constructor
        Parser();

        /**
         * @brief Parse raw data (.txt) to a vector of pairs
         * 
         * @param fileName 
         */
        void parseData(std::string fileName);

        std::vector<std::pair<int, int>> data_;
};