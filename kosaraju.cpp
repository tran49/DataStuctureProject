#include "kosaraju.h"

Kosaraju::Kosaraju(Graph graph) {
    graph_ = graph;
    incomingList_ = graph_.getIncomingAdjacencyDict();
    outgoingList_ = graph_.getOutgoingAdjacencyDict();
}

std::vector<std::set<int>> Kosaraju::getSCC() {
    std::stack<int> st;
    std::unordered_map<int, bool> visited;

    //first pass: go through each node and build a stack with decreasing finish times of dfs (last edge is at the top)
    for (auto& kV : outgoingList_) {
        if (visited[kV.first]) {
            continue;
        }
        buildStackDFS(kV.first, visited, st);
    }

    //clear the visited unordered_map as we have finished our first pass throught the graph
    visited.clear();

    std::vector<std::set<int>> sccVec;
    //second pass: use the stack we have built to find the strongly connected components
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if (visited[node]) {
            continue;
        }
        std::set<int> scc;
        buildStackDFS2(node, visited, scc);
        // std::cout<<"scc size: "<<scc.size()<<std::endl;
        sccVec.push_back(scc);
    }

    scc_ = sccVec;
    return sccVec;
}

void Kosaraju::buildStackDFS(int node, std::unordered_map<int, bool>& visited, std::stack<int>& st) {
    bool hasUnvisitedNeighbor = false;
    std::stack<int> recurSt;
    std::stack<int> callSt;
    recurSt.push(node);
    while(!recurSt.empty()) {
        node = recurSt.top();
        recurSt.pop();
        visited[node] = true;
        std::list<int> neighbors = outgoingList_[node];
        hasUnvisitedNeighbor = false;
        for (auto& vertex : neighbors) {
            hasUnvisitedNeighbor = true;
            if (!visited[vertex]) {
                recurSt.push(vertex);
            }
        }
        if (!hasUnvisitedNeighbor) st.push(node);
        else callSt.push(node);
    }
    while(!callSt.empty()) {
        st.push(callSt.top());
        callSt.pop();
    }
}

void Kosaraju::buildStackDFS2(int node, std::unordered_map<int, bool>& visited, std::set<int>& scc) {
    std::stack<int> recurSt;
    recurSt.push(node);
    while(!recurSt.empty()) {
        node = recurSt.top();
        recurSt.pop();
        visited[node] = true;
        // std::cout<<"Traversal Completion: "<<visited.size()/875713<<"%"<<std::endl;
        scc.insert(node);
        std::list<int> neighbors = incomingList_[node];
        for (auto& vertex : neighbors) {
            if (!visited[vertex]) {
                recurSt.push(vertex);
            }
        }
    }

}

void Kosaraju::write_to_file(std::string output_file) {
    std::ofstream output_stream;
    output_stream.open(output_file);

    for (auto i : scc_) {
        for (auto j : i) {
            output_stream << j << " ";
        }
        output_stream << std::endl;
    }

    output_stream.close();
}