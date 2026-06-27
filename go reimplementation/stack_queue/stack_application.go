// The Paper Folding Sequence (Dragon Curve)
package main

import (
	"fmt"
)

func sequenceprint(n int, direction string) {
	if n == 1 {
		fmt.Printf(" %s ", direction)
		return
	}

	sequenceprint(n-1, "R")

	fmt.Printf(" %s ", direction)

	sequenceprint(n-1, "L")

}

func main() {
	number := 1
	var direction string
	fmt.Println("sequence Printing")
	fmt.Printf("Enter A Number :\t")
	fmt.Scanln(&number)
	fmt.Printf("Enter A Direction :\t")
	fmt.Scanln(&direction)
	sequenceprint(number, direction)
	fmt.Println("")
}
