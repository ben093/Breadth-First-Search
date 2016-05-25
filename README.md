# Breadth-First-Search
A C++ implementation of Breadth First Search. CSC 325 - Algorithms    

Read one or more pairs of wrestler names from standard input. Names are separated by whitespace, so you can read them as strings using the normal >> operator. Each pair represents a rivalry. You can assume that the “rivalry graph” represented by the input is connected. Here is a sample input:  

    fang sally  
    shorty zephyr  
    the_machine big_earl  
    percival shorty  
    fang the_machine  
    sally shorty  
    
You must use a single breadth-first search to determine if the wrestlers can be partitioned into babyfaces and heels. (Hint: BFS/distances/even-odd.) To ensure that the output is unique, you must use the first wrestler in the first rivalry as the source for the breadth-first search; that first wrestler must be designated a babyface if a partition exists. Output the babyfaces and heels in sorted order to standard output, using the exact formats shown below.  

    BABYFACES  
    big_earl  
    fang  
    shorty  
    HEELS  
    percival  
    sally  
    the_machine  
    zephyr  
    
A partition exists for this sample input but may not exist in general. If no partition exists, output the following single line:  
    IMPOSSIBLE  
