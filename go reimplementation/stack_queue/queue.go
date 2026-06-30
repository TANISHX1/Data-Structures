// standard queue
package main

import (
	"fmt"
)

var queue [64]rune
var front, rear = -1, -1

func insert(char rune) {
	switch rear {
	case 63:
		fmt.Println("[Error] Queue overflow")
		return
	case -1:
		rear = 0
		front = 0
		queue[rear] = char
	default:
		rear++
		queue[rear] = char
	}
}

func delete() {
	if front == -1 || front == rear {
		fmt.Println("[Error] Queue underflow")
		return
	} else {
		queue[front] = 0
		front++
	}
}

func main() {
	for i := 0; i < 64; i++ {
		insert(rune(i))
	}
	fmt.Println(queue)
	fmt.Println(front)
	fmt.Println(rear)
	fmt.Println("done")
	for i := 0; i < 64; i++ {
		delete()
	}
}
