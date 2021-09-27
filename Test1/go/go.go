package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func partition(arr [10000]int, low, high int) ([10000]int, int) {
	pivot := arr[high]
	i := low
	for j := low; j < high; j++ {
		if arr[j] < pivot {
			arr[i], arr[j] = arr[j], arr[i]
			i++
		}
	}
	arr[i], arr[high] = arr[high], arr[i]
	return arr, i
}
func quickSort(arr [10000]int, low, high int) [10000]int {
	if low < high {
		var p int
		arr, p = partition(arr, low, high)
		arr = quickSort(arr, low, p-1)
		arr = quickSort(arr, p+1, high)
	}
	return arr
}
func main() {
	file, err := os.Open("../../data/10k_integers.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	var integers, sorted_integers [10000]int
	var i int
	scanner := bufio.NewScanner(file)
	// optionally, resize scanner's capacity for lines over 64K, see next example
	for scanner.Scan() {
		// fmt.Println(scanner.Text())
		integers[i], err = strconv.Atoi(scanner.Text())
		if err != nil {
			log.Fatal(err)
		}
		i++
	}
	sorted_integers = quickSort(integers, 0, len(integers)-1)

	// printf("First element: %d\nLast element: %d\n", integers[0], integers[10000 - 1]);

	fmt.Printf("First element: %#v\nLast element: %v\n", sorted_integers[0], integers[10000-1])
	// fmt.Println(sorted_integers[0])
	// fmt.Println(sorted_integers[len(sorted_integers)-1])

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}
}
