package main

// Función que realiza el ordenamiento en bubble sort
func bubbleSortV2(array *[]int) {
	done := false
	for i := 0; i < len(*array)-1; i++ {
		done = true
		for j := 0; j < len(*array)-i-1; j++ {
			if (*array)[j] > (*array)[j+1] {
				done = false
				(*array)[j], (*array)[j+1] = (*array)[j+1], (*array)[j] //intercambia
			}
		}
		if done {
			break
		}
	}

}