#pragma once

#include "graph.h"

#include <fstream>
#include <iostream>
#include <unordered_map>

class PageRank {
    public:
        /** @brief Default Constructor */
        PageRank(double decay = 0.85, int iteration = 100);

        /** @brief Graph Constructor */
        PageRank(Graph g, double decay = 0.85, int iteration = 100);

        /**
         * @brief Rank until reach iteration numbers or convergence
         * 
         */
        void rank();

        std::unordered_map<int, double> get_rank();

        /**
         * @brief Output result into an output file
         * 
         * @param output_file 
         */
        void write_to_file(std::string output_file);
    
    private:
        Graph g_;
        std::unordered_map<int, double> rank_;
        bool ranked_;
        double decay_;
        double iteration_;
};