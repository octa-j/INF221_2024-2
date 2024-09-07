package main

import (
	"bufio" //buffering
	"fmt"   //lectura/escritura
	"os"    //trabajar con archivos
	"slices"
	"strconv" //conversiones de tipo
	"strings" //funciones para strings
	"time"    //medir tiempos de ejecución
)

// Para gestión de errores
func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {

	// Solicita y recibe nombre del archivo y algoritmo a utilizar
	fmt.Print("Enter the filename: ")
	var filename string
	fmt.Scanln(&filename)
	fmt.Print("Enter the corresponding algorithm number: \n")
	fmt.Print("1. Bubble Sort\n2. Merge Sort\n3. Quick Sort\n4. Go Sort\n5. Bubble Sort V2\n")

	var algNum int
	fmt.Scanln(&algNum)

	// Open file
	file, err := os.Open(filename)
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	// Create a scanner to read the file
	scanner := bufio.NewScanner(file)

	// Increase the buffer size
	const maxLineSize = 10 * 1024 * 1024 // 10 MB buffer size
	buf := make([]byte, maxLineSize)
	scanner.Buffer(buf, maxLineSize)

	// Lee el arreglo
	if scanner.Scan() {
		line := scanner.Text()
		if len(line) == 0 {
			fmt.Println("The line is empty")
			return
		}

		// Imprime tamaño del string
		// for debugging
		fmt.Printf("Line length: %d\n", len(line))

		// Particiona el string en un arreglo
		parts := strings.Fields(line)
		fmt.Printf("Number of parts: %d\n", len(parts))

		// Lo vuelve arreglo de enteros
		array := make([]int, len(parts))
		for i, part := range parts {
			num, err := strconv.Atoi(part)
			if err != nil {
				fmt.Println("Error converting to integer:", err)
				return
			}
			array[i] = num
		}

		// Imprime largo del arreglo
		// for debugging
		fmt.Printf("Successfully read %d integers\n", len(array))

		// Crea el archivo en el que se ecribirán los resultados
		fmt.Print("Enter the results filename: ")
		var resname string
		fmt.Scanln(&resname)
		f, err := os.Create(resname)
		check(err)
		defer f.Close()
		w := bufio.NewWriter(f)

		// Crea subarreglo de tamaño n
		n := 10
		for n < 1000001 {
			subarr := make([]int, n)
			i := 0
			for i < n {
				subarr[i] = array[i]
				i++
			}

			// Mide tiempo de ejecución del algoritmo seleccionado
			start := time.Now()
			if algNum == 1 {
				bubbleSort(&subarr)
			} else if algNum == 2 {
				mergeSort(&subarr)
			} else if algNum == 3 {
				quickSort(&subarr)
			} else if algNum == 4 {
				slices.Sort(subarr)
			} else if algNum == 5 {
				bubbleSortV2(&subarr)
			}
			elapsed := time.Since(start)

			// escribe largo del subarreglo utilizado y el tiempo de ejecución
			_, err := fmt.Fprintf(w, "%d,%v\n", len(subarr), elapsed.Microseconds())
			check(err)
			w.Flush()

			// define intervalos para próximo sub arreglo
			if n < 100 {
				n += 10
			} else if n < 1000 {
				n += 100
			} else if n < 10000 {
				n += 1000
			} else if n < 100000 {
				n += 10000
			} else {
				n += 100000
			}

		}
		file.Close()
	} else {
		fmt.Println("Error scanning file:", scanner.Err())
	}
}
