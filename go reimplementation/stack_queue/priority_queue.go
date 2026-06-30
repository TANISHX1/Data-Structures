// priority queue
package main

import (
	"fmt"
	"math/rand/v2"
)

type node struct {
	char     rune
	priority int
}

var queue []node

func insert(char rune, priority int) {
	new_node := node{
		char:     char,
		priority: priority,
	}
	if len(queue) == 0 {
		queue = append(queue, new_node)
		return
	}
	for i := 0; i < len(queue); i++ {
		if queue[i].priority >= new_node.priority {
			// append has limitations so we used variadicunpacker
			queue = append(queue[:i], append([]node{new_node}, queue[i:]...)...)
			return
		}
	}
	queue = append(queue, new_node)

}

func delete() {
	if len(queue) == 0 {
		fmt.Println("[ Error ] Queue underflow")
		return
	}
	fmt.Println(queue[len(queue)-1])
	queue = queue[:len(queue)-1]
}

func main() {
	fmt.Println("Priority queue")
	for i := 0; i < 10; i++ {
		insert(rune(i), rand.Int()%100)
	}
	fmt.Println(queue)
	delete()
	fmt.Println(queue)
	insert(rune(44), rand.Int()%100)
	fmt.Println(queue)
	// delete()
}
