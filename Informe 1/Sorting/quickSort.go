package main

import (
	"bufio"   //buffering
	"fmt"     //lectura/escritura
	"os"      //trabajar con archivos
	"strconv" //conversiones de tipo
	"strings" //funciones para strings
)

// para gestión de errores
func check(e error) {
	if e != nil {
		panic(e)
	}
}

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

/* Archivo general:
lee el archivo con los datos
crea el archivo para ingresar los datos finales
almacena los datos en un arreglo de enteros
llama a la función quick sort
escribe los datos formateados sobre el archivo solution
*/

func main() {
	// archivo en el que se encuentran los datos
	file, err := os.Open("dataset.txt")
	check(err)

	defer file.Close()
	// archivo en el que se ecribirán los arreglos ordenados
	f, err := os.Create("solution.txt")
	check(err)

	defer f.Close()

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		// lee y separa cada en linea en un arreglo
		line := scanner.Text()
		lineSplit := strings.Split(line, " ")

		//convierte de tipo string a entero
		var array []int
		for _, val := range lineSplit {
			num, err := strconv.Atoi(val)
			check(err)
			array = append(array, num)
		}

		//llamado a quick sort
		quickSort(&array)

		// escribe los arreglos ordenados y formateados en archivo txt
		w := bufio.NewWriter(f)

		_, err := fmt.Fprintf(w, "%v\n", array)
		check(err)

		w.Flush()

	}

}
