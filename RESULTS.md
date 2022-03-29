# Project Results

## 1. Project Goals
All projects goals that we listed are met, including implentation of
- Graph
- One traversal (DFS)
- 2 complex algorithm: PageRank and Kosaraju

All of our data structures and algorithms were successfully tested and executed with the subsets of data and the original dataset

## 2. Runtime
The runtime of our algorithms meet with our proposal:
- DFS: O(m+n)
- PageRank: O(k*(m+n))
- Kosaraju's Algorithm: O(m+n)

The actual runtime on the real dataset on a virtual machine:
- PageRank: ~214.348s
- Kosaraju's: ~15s

## 3. Results and Findings
We ran through the whole dataset, and output our results under ```results``` folder.

The result format is as follow:
- ```kosaraju```: Pages in a connected component on a single row, different SSCs in different rows.
- ```pagerank```: One page and its rank on a single row, each page on a separate row.

Through the project, we were able to learn the following in the dataset:
- What page has the highest rank and how to rank pages based on relevance? (PageRank). After this, we understand a little bit about how Google ranks the pages when we search up things.
- Which websites are strongly connected to each other? With our output, lonely websites' rank can be improved by connecting to a large cluster of strongly connected components.
