package main
import(
	"fmt" 		//lectura/escritura
	"bufio" 	//buffering
	"os" 		//trabajar con archivos
	"strings" 	//funciones para strings
	"strconv" 	//conversiones de tipo
)

/// Para gestión de errores
func check(e error){
	if e != nil{
		panic(e)
	}
}

//Función que realiza el ordenamiento en bubbles sort
func bubbleSort(array *[]int){
	for i:=0; i< len(*array)-1; i++ {
		for j:=0; j < len(*array)-i-1; j++ {
		   if ((*array)[j] > (*array)[j+1]) {
			  (*array)[j], (*array)[j+1] = (*array)[j+1], (*array)[j] //intercambia
		   }
		}
	 }

}


/* Archivo general:
		lee el archivo con los datos
		crea el archivo para ingresar los datos finales
		almacena los datos en un arreglo de enteros
		llama a la función bubble sort
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

		//llamado a bubble sort
		bubbleSort(&array) 

		// escribe los arreglos ordenados y formateados en archivo txt
		w := bufio.NewWriter(f)

		_, err := fmt.Fprintf(w, "%v\n", array)
		check(err)

		w.Flush()
		

	}

}

