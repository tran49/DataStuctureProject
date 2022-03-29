#include "pagerank.h"

PageRank::PageRank(double decay, int iteration) {
    decay_ = decay;
    iteration_ = iteration;
    ranked_ = false;
}

PageRank::PageRank(Graph g, double decay, int iteration) {
    g_ = g;
    decay_ = decay;
    iteration_ = iteration;
    double initial_rank = 1 / (double)g_.getOutgoingAdjacencyDict().size();

    // Init rank of all nodes
    for (auto i : g_.getOutgoingAdjacencyDict()) {
        rank_.insert(std::pair<int, double>(i.first, initial_rank));
    }

    ranked_ = false;
}

void PageRank::rank() {
    if (ranked_)
        return;

    // TODO: Implement rank until convergence
    // CONVERGENCE
    for (int i = 0; i < iteration_; i++) {
        bool converged = true;
        double add = 0;
        std::unordered_map<int, double> old_rank(rank_);

        for (auto iter : rank_) { // O (N * summation of deg(v0 -> n))
            int node = iter.first;
            double new_rank = 0;
            for (auto incoming_node : g_.incomingAdjacentVertexes(node)) {
                new_rank += old_rank[incoming_node] / g_.outgoingAdjacentVertexes(incoming_node).size();
            }
            new_rank = (new_rank * decay_) + (1 - decay_) / rank_.size();

            // Store new rank
            rank_[node] = new_rank;

            // If current node has no outgoing links, save the old rank to "add"
            if (g_.outgoingAdjacentVertexes(node).size()==0) {
                add += old_rank[node];
            }       
        }
        // Update add
        add *= decay_ / rank_.size();

        // Increase the rank of each node by "add" (rank from nodes that does not have outgoing links)
        for (auto iter : rank_) {
            int node = iter.first;
            rank_[node] += add;
            if (fabs(rank_[node] - old_rank[node]) > 0.00001) {
                converged = false;
            }
        }
        
        // if the ranks converge, the process is finished;
        if (converged == true) {
            break;
        }

    }

    ranked_ = true;
}

std::unordered_map<int, double> PageRank::get_rank() {
    return rank_;
}

/**
 * @brief Output pagerank result into an output file
 * 
 * @param output_file 
 */
void PageRank::write_to_file(std::string output_file) {
    if (!ranked_) {
        rank();
    }
    std::ofstream output_stream;
    output_stream.open(output_file);
    for (auto i : rank_) {
        output_stream << i.first << " " << i.second << std::endl; 
    }
    output_stream.close();
}