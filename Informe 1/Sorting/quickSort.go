package main

// Función que ordena los datos de forma recursiva
// divide el arreglo original en sub arreglos cada vez más pequeños

func quickSort(array *[]int) {
	// si el arreglo tiene largo menor a 2 retorna
	if len(*array) < 2 {
		return
	} else {
		// en caso constrario define un pívote
		pivot := (*array)[0]

		// arreglo para valores mayores y menores al pívote
		var larger []int
		var smaller []int

		// recorre arreglo sub asignando a arreglo correspondiente
		for i := 1; i < len(*array); i++ {
			val := (*array)[i]
			if val > pivot {
				larger = append(larger, val)
			} else {
				smaller = append(smaller, val)
			}

		}

		// llamado recursivo para cada sub arreglo
		quickSort(&larger)
		quickSort(&smaller)

		// junta los sub arreglos ordenados
		// menores + pivote + mayores
		*array = append(smaller, pivot)
		for j := 0; j < len(larger); j++ {
			*array = append(*array, larger[j])

		}

	}

}
