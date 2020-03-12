#Defining functions

def arr_in():
    size = int(input("Please input the size of an array of which the determinant will be calculated: "))
    array = list()
    for i in range(size):
        array.append(list())
        for j in range(size):
            ext = input("Please input the element [" + str(int(i / size) + 1) + "][" + str(i % size + 1) + "] of the array > ")
            array[i].append(int(ext))
    return array

def print_arr(array):
    print("Input matrix:")
    for i in range(0, len(array)):
        print(array[i])

def det(array):
    if len(array[0]) == 1:
        determinant = array[0][0]
    else:
        #Laplace's expansion
        determinant = 0
        for i in range(0, len(array)):
            #temporary smaller array
            tmp = list()
            for j in range(1, len(array)):
                tmp.append(list())
                for k in range(1, len(array)):
                    if k - 1 < i:
                        tmp[j - 1].append(array[j][k - 1])
                    else:
                        tmp[j - 1].append(array[j][k])
        #Calculating determinant
            if not i%2:
                determinant = determinant + array[0][i] * det(tmp)
            else:
                determinant = determinant - array[0][i] * det(tmp)
    return determinant

#CODE
("Matrix determinant calculator.")
array = arr_in()
print_arr(array)
print("Determinant of the following matrix is: " + str(det(array)))
