// single circular linked list with insertion at begin and deltete form anywhere
package main

import (
	// "data_struct/color"
	"data_struct/color"
	"fmt"
	"math/rand/v2"
)

type node struct {
	node_id   int
	data      string
	next_node *node
}

var head *node
var count int = 0
var tail *node

func main() {
	fmt.Println("Circular linked list ")

	for i := 0; i < 10; i++ {
		insert("tanish")
	}
	transverse(1)

	fmt.Println("Deletion Start")
	for i := 0; i < 10; i++ {
		randomint := rand.IntN(10)
		fmt.Printf("%s Deleting %d%s\n", color.BgCyan, randomint, color.Reset)
		delete(randomint)
		transverse(1)
		fmt.Println("")
	}

}
func insert(data string) {
	new_node := &node{
		node_id: count,
		data:    data,
	}
	if head == nil {
		head = new_node
		tail = new_node
	} else {
		new_node.next_node = head
		head = new_node
	}
	count++
	tail.next_node = head
}

func format_print(pos *node) string {
	return fmt.Sprintf(" Node [%d] | data: %-55s | next Node [%p] \n", pos.node_id, pos.data, pos.next_node)

}

func transverse(cylcles uint8) {
	if head == nil {
		fmt.Println("Empty linked list")
		return
	}
	pos := head
	counter := 1
	for ; cylcles > 0; cylcles-- {

		// print first node , because pos != head or tail.next_node  create issue
		fmt.Printf("%s", format_print(pos))
		pos = pos.next_node

		for pos != tail.next_node {
			fmt.Printf("%s", format_print(pos))
			pos = pos.next_node
		}
		fmt.Printf("\tcycles completed : %d\n\n", counter)
		counter++
	}
}

func delete(node_id int) {
	// Case : 0 node
	if head == nil {
		fmt.Println("Can't Delete ,List is Empty")
		return
	}

	if head == tail && head.node_id == node_id {
		tail = nil
		head = nil
		return
	}
	pos := head

	if pos.node_id == node_id {
		head = head.next_node
		tail.next_node = head
		return
	} else {
		temp := pos
		pos = pos.next_node
		for pos != tail.next_node {
			if pos.node_id == node_id {
				temp.next_node = pos.next_node
				if pos.next_node == head {
					tail = temp
				}
				break

			}
			temp = pos
			pos = pos.next_node
		}
	}

}
