#Defining functions

import numpy as np

def arr_in():
    size = int(input("Please input the size of an array of which the determinant will be calculated: "))
    array = list()
    for i in range(size):
        array.append(list())
        for j in range(size):
            ext = input("Please input the element [" + str(int(i / size) + 1) + "][" + str(i % size + 1) + "] of the array > ")
            array[i].append(int(ext))
    return array

def det(array):
    if len(array[0]) == 1:
        det = array[0][0]
    else:
        det = "wip"
    return det

("Matrix determinant calculator.")
array = arr_in()
print("Input matrix:")
for i in range(0, len(array)):
    print(array[i])
print("Determinant of the following matrix is: " + str(det(array)))
