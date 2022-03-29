#include "traversals.h"

Traversal::Traversal(){};

Traversal::Traversal(std::unordered_map<int, std::list<int> > graph) {
    graph_ = graph;
}

std::string Traversal::message() {
    return "Hello, World!";
}

bool Traversal::dfs(int curr, int destination, std::unordered_map<int, bool> visited) {
    visited[curr] = true;
    if (curr == destination) {
        return true;
    }
    for (auto& neighbor : graph_[curr]) {
        if (visited[neighbor]) continue;
        if (dfs(neighbor, destination, visited)) {
            return true;
        }
    }
    return false;
}

std::vector<int> Traversal::pathToNode(int curr, int destination, std::unordered_map<int, bool> visited, std::vector<int>& path) {
    visited[curr] = true;
    path.push_back(curr);
    if (curr == destination) {
        return path;
    }
    for (auto& neighbor : graph_[curr]) {
        if (visited[neighbor]) continue;
        if (!pathToNode(neighbor, destination, visited, path).empty()) return path;
    }
    return {};
}