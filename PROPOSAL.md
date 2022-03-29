# CS 225 Final Project Proposal
- <b>Team:</b> dijkstra's problem child
- <b>Members:</b> atran49, minhtp2, dvalen25, jonahlt2

## Leading Question
What is the best website based on relevance? Which websites are strongly connected to each other?
 
## Dataset Acquisition and Processing:
<b>Dataset:</b>
- Source: https://snap.stanford.edu/data/web-Google.html 
- Description: Our Dataset is a Google web graph, in which Nodes represent web pages and directed edges represent hyperlinks between them. That means that the graph data can tell us about how we can get from one site to another through hyperlinks.

<b>Data Acquisition and Processing </b>
- We will download the dataset from the Stanford Network Analysis Project site, and include the authors' citation in our project:
    - J. Leskovec, K. Lang, A. Dasgupta, M. Mahoney. Community Structure in Large Networks: Natural Cluster Sizes and the Absence of Large Well-Defined Clusters. Internet Mathematics 6(1) 29--123, 2009.
Google programming contest, 2002


- We then store our dataset locally, in our respective machines. For testing on EWS purposes we will upload our dataset there too. We want to also take a subset of our dataset for testing and push it to the github repository.
- Dataset specifications:
    - Directed, unweighted
    - 875713 nodes, 5105039 edges
    - 2 columns representing source node and target node
    - Each node should be represented as a unique integer ID
 
<b> Error Handling </b>
- Make sure to handle empty lines when parsing.
- Make sure to ignore non digit characters, because our data format is in node ID which is an integer.
- Make sure to have only two distinct integers for each line in the data set.
- Make sure to get rid of duplicate entries if there are any.
 
 
## Graph Algorithms:
 
1. PageRank Algorithm
- Input: Adjacency List representing the graph OR the graph itself
- Output: A matrix of page rank values/weights of of the websites
- Runtime: O(k*(m+n)) where k is the number of iterations to reach convergence
- Space Complexity: O(n) where n is the number of nodes

2. Kosaraju's Algorithm
- Input: Adjacency List representing the graph OR the graph itself
- Output: Strongly connected components in a Graph
- Runtime: O(m+n)
- Space Complexity: O(n)

3. Depth First Search
- Input: An Adjacency List representing the graph OR a graph itself
- Output: The path from one node to another node OR whether a node can traverse to another
- Runtime: O(m+n)
- Space Complexity: O(m+n)

## Timeline:
### Week 1: <br>
- Setup the repo environment (Makefile)
- Parse the data (.txt)
- Implement the data structure storing the data (adjacency list)
- Unit Tests for parser and data structure
= Implement 1 kind of traversal (partially implemented)
### Week 2: <br>
- Finish traversal
- Implement Kosaraju’s algorithm
- Unit Tests for traversal and Kosaraju
### Week 3: <br>
- Implement PageRank algorithm (partially implemented or fully implemented)
- Unit Tests for PageRank algorithm
### Week 4: <br>
- Implement PageRank algorithm (fully implemented)
- Unit Tests for PageRank algorithm
- (Sketch Goal) Add visualization to the project (cs225::PNG)
