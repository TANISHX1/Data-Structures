// standard bst
package main

import (
	"data_struct/color"
	"fmt"
	"math/rand"
)

type node struct {
	node_id    int
	value      rune
	left_node  *node
	right_node *node
}

var count = 0

func insert(value rune, root *node) *node {
	if root == nil {
		new_node := &node{
			node_id: count,
			value:   value,
		}
		count++
		return new_node
	} else {
		if value <= root.value {
			root.left_node = insert(value, root.left_node)
		} else if value > root.value {
			root.right_node = insert(value, root.right_node)
		}
	}
	return root

}

func format_print(pos *node) {
	fmt.Printf("  Left Node [%s%-15p%s] | node [%d] | value : %-5q | Right Node [%s%-15p%s]\n", color.FgMagenta, pos.left_node, color.Reset, pos.node_id, pos.value, color.FgCyan, pos.right_node, color.Reset)
}

// option =1 : Preorder
// option =2 : inorder
// option =3 : Postorder
func transverse(option int, root *node) {
	if root == nil {

		return
	}
	switch option {
	case 1:
		format_print(root)
		transverse(option, root.left_node)
		transverse(option, root.right_node)
	case 2:
		transverse(option, root.left_node)
		format_print(root)
		transverse(option, root.right_node)
	case 3:
		transverse(option, root.left_node)
		transverse(option, root.right_node)
		format_print(root)
	}
}
func delete(value rune, root *node) *node {
	if root == nil {
		return root
	}
	if value < root.value {
		root.left_node = delete(value, root.left_node)
	} else if value > root.value {
		root.right_node = delete(value, root.right_node)
	} else {

		if root.left_node == nil {
			return root.right_node
		} else if root.right_node == nil {
			return root.left_node
		} else {
			var succesor *node = root.right_node
			for succesor.left_node != nil {
				succesor = succesor.left_node
			}
			root.value = succesor.value
			root.right_node = delete(succesor.value, root.right_node)
		}

	}
	return root
}

func main() {
	fmt.Printf("%s Binary Search Tree%s\n", color.Bold, color.Reset)
	var root *node
	var del []rune
	for i := 0; i < 10; i++ {
		num := rand.Intn(1000)
		root = insert(rune(num), root)
		del = append(del, rune(num))
	}
	fmt.Printf("%s Pre Order Transversal %s\n", color.Bold, color.Reset)
	transverse(1, root)

	fmt.Printf("%s In Order Transversal %s\n", color.Bold, color.Reset)
	transverse(2, root)

	fmt.Printf("%s Post Order Transversal %s\n", color.Bold, color.Reset)
	transverse(3, root)

	delete(del[0], root)
	fmt.Println("---------------------------------")
	transverse(2, root)
	delete(del[1], root)
	fmt.Println("---------------------------------")
	transverse(2, root)
}
