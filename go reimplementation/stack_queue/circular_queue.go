// circular queue
package main

import (
	"data_struct/color"
	"fmt"
)

var queue [64]rune
var front, rear = -1, -1

func insert(char rune) {
	switch rear {
	case front - 1:
		fmt.Println("Queue Overflow")
		return
	case -1:
		front = 0
		rear = 0
		queue[rear] = char
	case 63:
		if front == 0 {
			fmt.Println("Queue Overflow")
			return
		}
		rear = 0
		queue[rear] = char
	default:
		rear++
		queue[rear] = char
	}
}

func delete() {
	if front == -1 {
		fmt.Println("[ Error ] Queue underflow")
		return
	}
	queue[front] = 0
	if front == rear {
		front = -1
		rear = -1
		return
	}
	front = (front + 1) % 64
}
func printqueue() {
	fmt.Printf("%s %sQueue %s\n :", color.Bold, color.FgBrightMagenta, color.Reset)
	fmt.Println(queue)
}

func main() {
	fmt.Printf("Circular queue\n No.of Insertions :\t ")
	input := 0
	fmt.Scanln(&input)
	for i := 0; i < input; i++ {
		insert(rune(i))
	}
	printqueue()
	for i := 0; i < 10; i++ {
		delete()
	}
	printqueue()
	for i := 0; i < 9; i++ {
		insert(rune(i))
	}
	printqueue()

}
