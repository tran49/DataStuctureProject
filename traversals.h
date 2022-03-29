#pragma once
#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <iostream>

class Traversal {
    public:
        // TODO: Graph Constructor

        /**
         * @brief Default Constructor
         * 
         */
        Traversal();
        
        /**
         * @brief Adjacency List Constructor
         * 
         * @param graph 
         */
        Traversal(std::unordered_map<int, std::list<int> > graph);

        /**
         * @brief DFS to know whether we can go from a node to anotehr
         * 
         * @param curr 
         * @param node 
         * @param visited 
         * @return true 
         * @return false 
         */
        bool dfs(int curr, int node, std::unordered_map<int, bool> visited = std::unordered_map<int, bool>());
        
        /**
         * @brief Get path to a node
         * 
         * @param curr 
         * @param destination 
         * @param visited 
         * @param path 
         * @return std::vector<int> 
         */
        std::vector<int> pathToNode(int curr, int destination, std::unordered_map<int, bool> visited = std::unordered_map<int, bool>(), std::vector<int>& path = *(new std::vector<int>()));
        
        /**
         * @brief Test
         * 
         * @return std::string 
         */
        std::string message();

    private:
        std::unordered_map<int, std::list<int> > graph_;
};