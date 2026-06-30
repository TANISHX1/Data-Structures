// dequeue implementation , using in multiplexing and tread management
package main

import (
	"data_struct/color"
	"fmt"
	"math/rand/v2"
)

type node struct {
	node_id int
	value   rune
	prev    *node
	next    *node
}

var ValidSymbols = [...]rune{
	' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
	':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}', '~',
}

var queue *node
var node_count = 0
var tail *node

func insert_front(value rune) {
	new_node := &node{
		node_id: node_count,
		value:   value,
		next:    queue,
	}
	if queue == nil {
		tail = new_node
		queue = new_node
		node_count++
		return
	}
	queue.prev = new_node
	queue = new_node
	node_count++
}
func delete_front() *node {
	if queue == nil {
		fmt.Printf("[%s Error %s ] : Queue underflow\n", color.FgRed, color.Reset)
		return nil
	}

	deleted_node := queue
	if queue == tail {
		queue = nil
		tail = nil
		return deleted_node
	}
	queue = queue.next
	queue.prev = nil
	return deleted_node
}

func insert_end(value rune) {
	new_node := &node{
		node_id: node_count,
		value:   value,
		prev:    tail,
	}
	if tail == nil {
		queue = new_node
		tail = new_node
		node_count++
		return
	}
	tail.next = new_node
	new_node.prev = tail
	tail = new_node
	node_count++
}

func delete_end() *node {
	if tail == nil {
		fmt.Printf("[%s Error %s ] : Queue underflow\n", color.FgRed, color.Reset)
		return nil
	}
	deleted_node := tail
	if queue == tail {
		queue = nil
		tail = nil
		return deleted_node
	}
	tail = tail.prev
	tail.next = nil
	return deleted_node
}

func transverse(dxn bool) {
	if dxn {
		fmt.Printf("%s Transversing From Front %s\n", color.Bold, color.Reset)
		for pos := queue; pos != nil; pos = pos.next {
			format_print(pos)
		}
	} else {
		fmt.Printf("%s Transversing From End %s\n", color.Bold, color.Reset)
		for pos := tail; pos != nil; pos = pos.prev {
			format_print(pos)
		}
	}
}

func main() {
	fmt.Println("Deque")
	for i := 0; i < 10; i++ {
		if i%2 == 0 {
			insert_front(ValidSymbols[rand.IntN(32)])
		} else {
			insert_end(ValidSymbols[rand.IntN(32)])
		}

	}
	transverse(true)
	// fmt.Println(delete_front())
	transverse(false)

	for i := 0; i < 8; i++ {
		if i%2 == 0 {
			delete_end()
		} else {
			delete_front()
		}
	}
	transverse(true)
	transverse(false)
	delete_end()
	delete_front()
	transverse(false)

}

func format_print(pos *node) {
	fmt.Printf("Previous [%-12p] | Node [%d] | Value: %c | next Node [%-12p] \n", pos.prev, pos.node_id, pos.value, pos.next)
}
