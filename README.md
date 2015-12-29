# relax
[Relaxation labelling](https://en.wikipedia.org/wiki/Relaxation_labelling) is an image treatment methodology. Its goal is to associate a label to the pixels of a given image or nodes of a given graph.

# Usage
Compile:
```bash
make
```

Provide input file, e.g. `pixels.dat`, consisting of the initial edge probabilities for each pixel in the image:
```
  0.0 0.0 0.0 0.0 0.0
  0.0 0.1 0.1 0.1 0.0
  0.0 0.1 1.0 0.1 0.0
  0.0 0.1 0.1 0.1 0.0
  0.0 0.0 0.0 0.0 0.0
  
  "pixels.dat" 5L, 115C   
```

Run program with the input file and iteration amount:
```bash
./relax pixels.dat 2

---------------------------------------
ITERATION 1:
---------------------------------------
0       0       0       0       0	
0       0.0932	0.09206	0.0932	0	
0       0.09206	1       0.09206	0	
0       0.0932	0.09206	0.0932	0	
0       0       0       0       0	
---------------------------------------
ITERATION 2:
---------------------------------------
0       0       0       0       0	
0       0.0869	0.08484 0.0869	0	
0       0.08484 1       0.08484 0	
0       0.0869	0.08484 0.0869	0	
0       0       0       0       0 	
---------------------------------------
---------------------------------------

 

```
