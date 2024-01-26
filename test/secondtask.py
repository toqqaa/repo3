#TASK: Run the cell below to create an array of random numbers and see if you can figure out how it works.
#TASK: What are the largest and smalled values in this array? 
import numpy as np
np.random.seed(101)
arr = np.random.randint(low=0, high=100, size=(5, 5))
print(arr)
largest = np.amax(arr)
smallest = np.amin(arr)
print("The Largest element in this array is:", largest)
print("The Smallest element in this array is:", smallest)