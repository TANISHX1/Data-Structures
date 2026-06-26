package linkedlist
//Build and traverse lists using recursion instead of iterative loops.

package main

import (
	"fmt"
)

type node struct {
	node_id   int
	next_node *node
}

var count = -1

func insert(node_ *node) *node {
	if node_ == nil {
		count++
		return &node{
			node_id: count,
		}
	}
	node_.next_node = insert(node_.next_node)
	return node_
}

func format_print(pos *node) string {
	return fmt.Sprintf(" Node [%d] | next Node [%p] \n", pos.node_id, pos.next_node)

}

func transverse(head *node) {
	if head == nil {
		fmt.Println("list is Empty")
		return
	}
	for pos := head; pos != nil; pos = pos.next_node {
		fmt.Printf("%s", format_print(pos))
	}
}

func main() {
	var head *node
	for i := 0; i < 10; i++ {
		head = insert(head)
	}
	transverse(head)
}
