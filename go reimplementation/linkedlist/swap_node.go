package linkedlist
// swapping nodes in linked list 

package main

import (
	"data_struct/color"
	"fmt"
	"os"
	"strings"
)

type node struct {
	node_id   int
	data      string
	next_node *node
}

var head *node

func open_file() (string, error) {
	file, err := os.ReadFile("/home/blazex/Documents/Random_Testing Data/random_string_data/random_100_short_lines.txt")
	if err != nil {
		return "", err
	} else {
		fmt.Printf("%s file successfully opened%s\n", color.FgBrightCyan, color.Reset)
		return string(file), nil
	}

}

func swap_node(node_id1, node_id2 int) {
	if head == nil {
		fmt.Println("List is Empty")
		return
	}
	if node_id1 > count || node_id2 > count {
		fmt.Printf("%s Invalid Location {node with that id don't exist} , max node in list is %d %s\n", color.FgRed, count, color.Reset)
		return
	}
	pos := head
	var temp1, temp2, node_1, node_2 *node
	for pos != nil {
		if pos.node_id == node_id1 {
			node_1 = pos
		}
		if pos.node_id == node_id2 {
			node_2 = pos
		}
		if node_1 == nil {
			temp1 = pos
		}
		if node_2 == nil {
			temp2 = pos
		}
		pos = pos.next_node
	}
	if node_1 == head || node_2 == head {
		if node_1 == head {
			pos = node_1.next_node
			temp2.next_node = node_1
			node_1.next_node = node_2.next_node
			node_2.next_node = pos
			head = node_2
		} else {
			pos = node_2.next_node
			temp1.next_node = node_2
			node_2.next_node = node_1.next_node
			node_1.next_node = pos
			head = node_1
		}
		return
	}
	// connecting previous node
	temp1.next_node = node_2
	temp2.next_node = node_1
	// updating temp node with swap_node.next_node
	temp1 = node_1.next_node
	temp2 = node_2.next_node
	// connecting next node
	node_1.next_node = temp2
	node_2.next_node = temp1
}

var count = 0

func initalize_list(total_node int) {
	data, err := open_file()
	if err != nil {
		fmt.Printf("%s Failed to open file %s\n", color.FgRed, color.Reset)
		return
	}

	stripped_data := strings.Split(data, "\n")
	pos := head
	for ; total_node > 0; total_node-- {

		new_node := &node{
			node_id: count,
			data:    stripped_data[count%len(stripped_data)],
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

	fmt.Printf("%s List initalization completed !..%s\n", color.FgGreen, color.Reset)
}

func format_print(pos *node) string {
	return fmt.Sprintf(" Node [%d] | data: %-55s | next Node [%p] \n", pos.node_id, pos.data, pos.next_node)

}

func transverse() {
	pos := head
	for pos != nil {
		fmt.Printf("%s", format_print(pos))
		pos = pos.next_node
	}
}

func main() {
	fmt.Printf("%s Swapping Nodes %s\n", color.Bold, color.Reset)

	initalize_list(5)
	transverse()
	fmt.Println("Swapping")
	swap_node(1, 2)
	transverse()
	fmt.Println("-------------------------------------------------------------")
	swap_node(0, 4)
	transverse()
}
