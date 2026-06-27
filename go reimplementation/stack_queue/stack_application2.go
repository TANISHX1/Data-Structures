package stackqueue
// The Bounded Tower (Adjacent-Only ToH)
package main

import (
	"fmt"
)

var count = 0

func a_toh(n_disk int, source, destination, auxiliary string) {
	if n_disk == 1 {
		fmt.Println("Move Disk 1 From ", source, " To ", auxiliary)
		count++
		fmt.Println("Move Disk 1 From ", auxiliary, " To ", destination)
		count++
		return
	}

	a_toh(n_disk-1, source, destination, auxiliary)
	fmt.Println("Move Disk ", n_disk, " From ", source, " To ", auxiliary)
	count++
	a_toh(n_disk-1, destination, source, auxiliary)
	fmt.Println("Move Disk ", n_disk, " From ", auxiliary, " To ", destination)
	count++
	a_toh(n_disk-1, source, destination, auxiliary)
}

func main() {
	fmt.Println("Abjecent TOH")
	number := 0
	fmt.Printf("Enter the number :\t")
	fmt.Scanln(&number)
	a_toh(number, "A", "C", "B")
	fmt.Println("Total Moves : ", count)
}
