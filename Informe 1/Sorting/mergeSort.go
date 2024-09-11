package main

// función que une dos subarreglos ordenados en uno, también ordenado
func merge(first *[]int, second *[]int) []int {
	i := 0
	j := 0
	sorted := []int{}

	//compara los primeros valores y los
	for i < len(*first) && j < len(*second) {
		if (*first)[i] < (*second)[j] {
			sorted = append(sorted, (*first)[i])
			i++
		} else {
			sorted = append(sorted, (*second)[j])
			j++
		}
	}
	for ; i < len(*first); i++ {
		sorted = append(sorted, (*first)[i])
	}
	for ; j < len(*second); j++ {
		sorted = append(sorted, (*second)[j])
	}
	return sorted
}

// función que realiza merge sort
func mergeSort(array *[]int) []int {
	if len(*array) < 2 {
		return (*array)
	}
	a := (*array)[:len(*array)/2]
	b := (*array)[len(*array)/2:]
	first := mergeSort(&a)
	second := mergeSort(&b)
	return merge(&first, &second)

}
