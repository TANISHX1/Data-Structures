// tower of honoi
package main

import (
	"fmt"
)

var count = 0

func toh(disk int, source, destination, auxiliary string) {
	count++
	if disk == 1 {
		fmt.Println("Move Disk 1 ", source, " to ", destination)
		return
	}
	toh(disk-1, source, auxiliary, destination)
	fmt.Println("Move disk ", disk, " From ", source, " to ", destination)
	toh(disk-1, auxiliary, destination, source)

}

func main() {
	fmt.Println("Tower Of Honoi")
	toh(5, "A", "C", "B")
	fmt.Println("Source : A ", "Destintion : C ", "Auxiliary : B ")
	fmt.Printf("Total moves : %d\n", count)
}
