# A High Performing Deep Neural Network 
An high performance artificial Neural Network program that classifies handwritten digits, trained with online images data and built upon matrix multiplication

## Overview
* Implemented a C++ version of a deep neural network that recognizes handwritten numbers on a Supercomnting Cluster
* Trained with 50000 online images and tested among 10000 images on 30 epoches, achieving more than 50% accuracy 
* Shaved of CPU usage and reduced memory time, optimizing performance of the neuralnet classification program with memory caching and SIMD parallelism techniques
  

## Environment
On the Ohio Supercomputing Center Pfizer cluster
| Component  | Details |
| ------------- | ------------- |
| CPU Model  | Intel(R) Xeon(R) Gold 6148 CPU @ 2.40GHz |
| CPU/Core Speed  | 2.40GHz   |
| RAM  | 200GB   |
| Operating system used | Linux 3.10.0-1160.95.1.el7.x86_64 #1 SMP x86_64 x86_64 x86_64 GNU/Linux    |
|Name and version of C++ compiler | gcc version 8.4.0 (GCC )  |
| Name and version of other non-standard software tools & components | Linux perf| 


## Original performance

Performance Statistics
| Rep |	User Time (s) | 	Elapsed Time (s) |	Peak memory (KB) |
| -------- | -------------- |  -------------- |  -------------- |
| 1	 | 32.77 | 33.45 | 3176 |
| 2	 | 31.88 | 32.48 | 3176 |
| 3	 | 31.40 | 31.95 | 3176 |
| 4	 | 32.24 | 32.91 | 3176 |
| 5	 | 32.94 | 33.62 | 3176 |

## Improved performance

Performance Statistics
| Rep |	User Time (s) | 	Elapsed Time (s) |	Peak memory (KB) |
| -------- | -------------- |  -------------- |  -------------- |
| 1	 | 9.47 | 09.75 | 98192 |
| 2	 | 9.70 | 09.97 | 98192 |
| 3	 | 9.36 | 09.64 | 98192 |
| 4	 | 9.47 | 09.77 | 98192 |
| 5	 | 9.34 | 09.64 | 98192 |

## Comparative runtime analysis

Performance Statistics
| Replicate# |	Reference | 	Improved |	
| -------- | -------------- |  -------------- |  
| 1	 | 33.45 | 09.75 | 
| 2	 | 32.48 | 09.97 | 
| 3	 | 31.95 | 09.64 | 
| 4	 | 32.91 | 09.77 | 
| 5	 | 33.62 | 09.64 | 
| Average	 | 32.882 | 9.754 | 
| SD	 | 0.6888904122 | 0.1350185172 | 
| 95% CI Range | 0.8553704235 | 0.167647632 | 
Stats |  32.882 ± 0.86  | 9.754 ± 0.17
T-Test (H0: μ1=μ2) | 0.00000007633396889 | 

## Conclusion
First, there’s a drastic change in elapsed runtime between two versions: from roughly 32.882 to 9.754 seconds. The t-test indicates that the change is significant, and it is achieved by following reasons. First, changing the matrix representation from 2d to 1d vector plays a key role which enables efficient caching, especially for matrix of size (n, 1). Second, previously, for every epoch, images is loaded automatically from disk space. In this version, a map is used to caches repetitive image file in many epochs, which reduce the I/O time. Note that the peak memory therefore increases by roughly 33 times. In conclusion, this version makes a good tradeoff of memory for runtime improvement.



