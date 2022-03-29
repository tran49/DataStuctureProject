# CS 225 Final Project
Authors: Minh Phan, Jonah Tjandra, David Sanchez, Tuan Tran

Presentation Video: https://illinois.zoom.us/rec/share/3lX-ok6AJjuyrCIXFd57yfJHyZLqwqxDt2jeDl9cL2MktI17FZ4sCL9bHIy1E61U.YTioMSLn9FVjZKxH

Presentation Slides: https://docs.google.com/presentation/d/1-go89R-BO-eE7wFrVblPWyui9DKQeveDnhikbAw1qeg/edit#slide=id.p

Summary: With a network dataset of hyperlinks from a website to another, we analyze the website rankings based on relevance and find the strongly connected website clusters.

## Dataset
The full dataset for this project can be accessed: https://snap.stanford.edu/data/web-Google.html

## Structure
```
.
├── data                    # Subsets of the datasets
├── results                 # Full results of the project 
├── tests                   # Tests
├── README.md
├── <document_files> (.md)
└── <project_source_files> (.h/.c)
```

We build the following classes in our project: ```Parser```, ```Graph```, ```Traversal```, ```Kosaraju```, ```Pagerank```.

## Execution
Build the project: ```make``` or ```make main```

Run the project: 
```bash
### Template
### <algorithm> ∈ {pagerank, kosaraju}
make
./main <algorithm> <input_file> <output_file>

### Example execution:
make
./main kosaraju web-Google.txt ./results/kosaraju.txt
```

## Test Suite
Build the tests:
- Command: ```make```
- Target: ```parser_test```, ```graph_test```, ```traversals_test```, ```kosaraju_test```, ```pagerank_test```

Run the test: ```./<target>```

All tests are inside ```tests``` folder, with each .cpp file represents a test for all functions in a class.
- ```parser_test```: Test whether the parser is parsing in data correctly (clean data)
- ```graph_test```: Test whether the graph data structure can parse in data and functions correctly
- ```traversals_test```: Test Depth First Search traversals (whether there is a path, the path is correct)
- ```kosaraju_test```: Test Kosaraju Algorithm (find strongly connected components)
- ```pagerank_test```: Test PageRank Algorithm (from simple to complex graph)

## Results
The output of the real dataset is inside ```results``` directory. This includes a run of kosaraju in the real dataset, and a run of pagerank until convergence.

The result format is as follow:
- ```kosaraju```: Pages in a connected component on a single row, different SSCs in different rows.
- ```pagerank```: One page and its rank on a single row, each page on a separate row.
