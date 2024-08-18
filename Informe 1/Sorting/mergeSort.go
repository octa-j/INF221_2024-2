package main
import (
	"fmt" 		//lectura/escritura
	"bufio" 	//buffering
	"os" 		//trabajar con archivos
	"strings" 	//funciones para strings
	"strconv" 	//conversiones de tipo
)




//para gestión de errores
func check(e error){
	if e != nil{
		panic(e)
	}
}


// función que une dos arreglos ordenados en uno, también ordenado
func merge(first []int, second []int) []int {
    i := 0
    j := 0
	sorted := []int{}

	//compara los primeros valores y los
    for i < len(first) && j < len(second) {
        if first[i] < second[j] {
            sorted = append(sorted, first[i])
            i++
			} else {
            sorted = append(sorted, second[j])
            j++
		}
    }
    for ; i < len(first); i++ {
        sorted = append(sorted, first[i])
    }
    for ; j < len(second); j++ {
        sorted = append(sorted, second[j])
    }
    return sorted
}




// función que realiza merge sort
func mergeSort(array []int) []int {
	if len(array) < 2 {
        return array
    }
    first := mergeSort(array[:len(array)/2])
    second := mergeSort(array[len(array)/2:])
    return merge(first, second)

}





/* Archivo general:
		lee el archivo con los datos
		crea el archivo para ingresar los datos finales
		almacena los datos en un arreglo de enteros
		llama a la función merge sort
		escribe los datos formateados sobre el archivo solution
*/

func main(){
	// archivo en el que se encuentran los datos
	file, err := os.Open("dataset.txt")
	check(err)

	defer file.Close()
	// archivo en el que se ecribirán los arreglos ordenados
	f, err := os.Create("solution.txt")
	check(err)
	
	defer f.Close()

	scanner := bufio.NewScanner(file)

	for scanner.Scan(){
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

		//llamado a merge sort
		array = mergeSort(array) 

		// escribe los arreglos ordenados y formateados en archivo txt
		w := bufio.NewWriter(f)

		_, err := fmt.Fprintf(w, "%v\n", array)
		check(err)

		w.Flush()
		

	}

}




