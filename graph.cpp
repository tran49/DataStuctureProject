#include "graph.h"

Graph::Graph() {
    /* Nothing to see here */
}

Graph::Graph(const Graph& other) {
    copy(other);
}

Graph::Graph(std::vector<std::pair<int, int>> data) {
    for (auto it : data) {
        int v1 = it.first;
        int v2 = it.second;
        
        // Construct outgoing adjacency list
        // This will work even when v1 did not exist
        adjacency_dict_outgoing_[v1].emplace_back(v2);
        if (adjacency_dict_outgoing_.find(v2) == adjacency_dict_outgoing_.end()) {
            adjacency_dict_outgoing_[v2] = std::list<int>();
        }

        // Construct incoming adjacency list
        adjacency_dict_incoming_[v2].emplace_back(v1);
        if (adjacency_dict_incoming_.find(v1) == adjacency_dict_incoming_.end()) {
            adjacency_dict_incoming_[v1] = std::list<int>();
        }
    }
}

Graph& Graph::operator=(const Graph& other) {
    if (&other != this) {
        copy(other);
    }
    
    return *this;
}

void Graph::insertVertex(int v) {
    if (adjacency_dict_outgoing_.find(v) == adjacency_dict_outgoing_.end()) {
        adjacency_dict_outgoing_[v] = std::list<int>();
    }
}

std::list<int> Graph::outgoingAdjacentVertexes(int v) {
    return adjacency_dict_outgoing_[v];
}

std::list<int> Graph::incomingAdjacentVertexes(int v) {
    return adjacency_dict_incoming_[v];
}

bool Graph::areAdjacent(int v1, int v2) {
    // Return whether v1 can go to v2
    if (adjacency_dict_outgoing_[v1].size() < adjacency_dict_incoming_[v2].size()) {
        for (auto i : adjacency_dict_outgoing_[v1]) {
            if (i == v2) {
                return true;
            }
        }
    } else {
        for (auto i : adjacency_dict_incoming_[v2]) {
            if (i == v1) {
                return true;
            }
        }
    }

    return false;
}

void Graph::insertEdge(int v1, int v2) {
    adjacency_dict_outgoing_[v1].emplace_back(v2);
    adjacency_dict_incoming_[v2].emplace_back(v1);
    if (adjacency_dict_outgoing_.find(v2) == adjacency_dict_outgoing_.end()) {
        adjacency_dict_outgoing_[v2] = std::list<int>();
    }
    if (adjacency_dict_incoming_.find(v1) == adjacency_dict_outgoing_.end()) {
        adjacency_dict_incoming_[v1] = std::list<int>();
    }
}

std::unordered_map<int, std::list<int>> Graph::getOutgoingAdjacencyDict() {
    return adjacency_dict_outgoing_;
}

std::unordered_map<int, std::list<int>> Graph::getIncomingAdjacencyDict() {
    return adjacency_dict_incoming_;
}

// Private
void Graph::copy(const Graph& other) {
    adjacency_dict_outgoing_ = other.adjacency_dict_outgoing_;
    adjacency_dict_incoming_ = other.adjacency_dict_incoming_;
}