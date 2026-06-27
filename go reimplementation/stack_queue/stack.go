// dynamic single stack
package main

import (
	"fmt"
	"math/rand/v2"
)

var stack []int //slice for dynamic arrays

func push(value int) {
	stack = append(stack, value)
	fmt.Println("Pushed : ", stack[len(stack)-1])
}

func pop() {
	if len(stack) == 0 {
		fmt.Println("Error : stack underflow")
		return

	}
	fmt.Println("Popped : ", stack[len(stack)-1])
	stack = stack[:len(stack)-1]

}
func top() int {
	if len(stack)-1 < 0 {
		fmt.Println("Error : stack top points to invalid stack element ")
		return -1
	}
	return stack[len(stack)-1]
}

func main() {

	for i := 0; i < 10; i++ {
		push(rand.Int())
		// push(i)
	}

	fmt.Println("Top stack is ", top())
	for i := 0; i < 10; i++ {
		pop()
	}
	fmt.Println("--------------------------------")

}
