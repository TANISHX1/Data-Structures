// finding middle node by Tortoise and Hare algorithm.

package main

import (
	"data_struct/color"
	"fmt"
)

type node struct {
	node_id   int
	next_node *node
}

var count = 0
var head, pos *node

func initalize_list(total_nodes int) {
	for ; total_nodes > 0; total_nodes-- {
		new_node := &node{
			node_id: count,
		}
		count++
		if head == nil {
			head = new_node
			pos = head
			continue
		}
		pos.next_node = new_node
		pos = new_node
	}
}

func format_print(pos *node) string {
	return fmt.Sprintf(" Node [%d] | next Node [%p] \n", pos.node_id, pos.next_node)

}

func transverse() {
	if head == nil {
		fmt.Println("list is Empty")
		return
	}
	for pos := head; pos != nil; pos = pos.next_node {
		fmt.Printf("%s", format_print(pos))
	}
}
func middle_node() {
	if head == nil {
		fmt.Println("list is Empty")
		return
	}
	slow := head
	fast := head
	prev := head
	for fast != nil && fast.next_node != nil {
		prev = slow
		slow = slow.next_node
		fast = fast.next_node.next_node
	}
	if fast == nil {
		fmt.Printf("\n%s Middle node 1 : %s %s", color.FgGreen, format_print(prev), color.Reset)
		fmt.Printf("\n%s Middle node 2 : %s %s", color.FgGreen, format_print(slow), color.Reset)
	} else {
		fmt.Printf("\n%s Middle node %s %s", color.FgGreen, format_print(slow), color.Reset)

	}

}

func main() {
	initalize_list(101)
	transverse()
	middle_node()
}
