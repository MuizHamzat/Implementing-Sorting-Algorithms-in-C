# Implementing Sorting Algorithms in C

This was an assignment from my MECHTRON2MP3 course.

THe purpose of this assignment was to implement the Bubble Sort, Insertion Sort, Merge Sort, Heap Sort, and Counting Sort algorithms in C. In the ```mySort_test.ipynb``` file, you can see the run time of each algorithm when dealing with large lists/arrays. Note that the ```mySort_test.ipynb``` file requires you have numpy installed.
 
To compile and run the code in main.c, you can type ```gcc main.c mySort.c mySort.h``` in the terminal, then run the executeable.\
\
And to recompile the code and create the shared library libmysort.so, you can type ```gcc -O3 -shared -o libmysort.so -fPIC mySort.c``` in the terminal, 
or, you can use the Makefile and simply type ```make```.
