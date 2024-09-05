package main

// Función que realiza el ordenamiento en bubble sort
func bubbleSort(array *[]int) {
	for i := 0; i < len(*array)-1; i++ {
		for j := 0; j < len(*array)-i-1; j++ {
			if (*array)[j] > (*array)[j+1] {
				(*array)[j], (*array)[j+1] = (*array)[j+1], (*array)[j] //intercambia
			}
		}
	}

}
