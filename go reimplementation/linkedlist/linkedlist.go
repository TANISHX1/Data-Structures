package main

import (
	"data_struct/color"
	"fmt"
)

type node struct {
	node_id       int
	data          string
	next_node     *node
	previous_node *node
}

var head *node

func insert_at_begin(x int, data string) {
	new_node := &node{
		node_id:   x,
		data:      data,
		next_node: head,
	}

	if head == nil {
		head = new_node
		return
	}
	head.previous_node = new_node
	head = new_node
}

func format_print(pos *node) string {
	return fmt.Sprintf("previousnode [%-12p] | Node [%d] | data: %-55s | next Node [%p] \n", pos.previous_node, pos.node_id, pos.data, pos.next_node)

}
func transverse() {
	if head == nil {
		return
	}
	pos := head
	fmt.Println("reached")
	for pos != nil {
		fmt.Printf("%s", format_print(pos))
		pos = pos.next_node
	}
}

func delete(node_id int) {
	pos := head
	if pos == nil {
		fmt.Println("linked is empty")
		return
	}
	flag := false
	for pos != nil {
		if pos.node_id == node_id {
			flag = true
			if pos.next_node == nil {
				pos.previous_node.next_node = nil
				break
			} else if pos.previous_node == nil {
				pos.next_node.previous_node = nil
				head = pos.next_node
				break
			} else {
				pos.previous_node.next_node = pos.next_node
				pos.next_node.previous_node = pos.previous_node
				break
			}
		}
		pos = pos.next_node
	}
	if flag {
		fmt.Println("Deleted Node :")
		fmt.Printf("%s%s%s", color.FgMagenta, format_print(pos), color.Reset)
	}

}

func main() {
	data_input := [10]string{
		"The quick brown fox jumps over the lazy dog",
		"She likes to read books in the quiet library.",
		"The bright sun shines in the blue sky",
		"I want to travel to the high mountains next year",
		"They eat fresh apples and sweet grapes every morning",
		"He works very hard to learn new computer skills",
		"We walk down the long street to see the big park.",
		"The little cat sleeps softly on the warm sofa.",
		"Every new day gives us a chance to start fresh.",
		"Music makes people feel happy and relaxed."}
	fmt.Println("Doubly Linked list insertion at Begin")
	for i := 0; i < 10; i++ {
		insert_at_begin(i, data_input[i])
	}
	transverse()
	fmt.Println("---------------------------------------------------")

	delete(4)
	transverse()
	delete(9)
	transverse()
	delete(0)
	transverse()
}
