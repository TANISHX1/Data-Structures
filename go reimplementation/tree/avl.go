// AVL tree
package main

import (
	"fmt"
	"math"
	"math/rand"
)

type node struct {
	node_id int
	value   rune
	left    *node
	right   *node
	height  int
	balance int
}

var counter = 0

func insert(value rune, root *node) *node {

	// finding the location and inserting the node
	if root == nil {
		new_node := &node{
			node_id: counter,
			value:   value,
		}
		counter++
		return new_node
	}
	if value <= root.value {
		root.left = insert(value, root.left)
	} else if value > root.value {
		root.right = insert(value, root.right)
	} else {
		return root
	}

	// updating the height
	root.height = 1 + int(math.Max(get_height(root.left), get_height(root.right)))
	// Balancing the tree

	if balance(root) > 1 {
		if value < root.left.value {
			return right_rotation(root)
		} else {
			root.left = left_rotation(root.left)
			return right_rotation(root)
		}
	}
	if balance(root) < -1 {
		if value > root.right.value {
			return left_rotation(root)
		} else {
			root.right = right_rotation(root.right)
			return left_rotation(root)
		}
	}
	root.balance = balance(root)
	return root
}

func left_rotation(root *node) *node {
	y := root.right
	z := y.left
	y.left = root
	root.right = z
	root.height = 1 + int(math.Max(get_height(root.left), get_height(root.right)))
	y.height = 1 + int(math.Max(get_height(y.left), get_height(y.right)))
	return y
}

func right_rotation(root *node) *node {
	y := root.left
	z := y.right
	y.right = root
	root.left = z
	root.height = 1 + int(math.Max(get_height(root.left), get_height(root.right)))
	y.height = 1 + int(math.Max(get_height(y.left), get_height(y.right)))
	return y
}

func get_height(root *node) float64 {
	if root == nil {
		return 0
	}
	return float64(root.height)
}

func balance(root *node) int {
	if root == nil {
		return 0
	}
	return int(get_height(root.left)) - int(get_height(root.right))
}

func preorder(root *node) {
	if root == nil {
		return
	}
	fmt.Printf(" Node [%d] | value [%6q] | height [%d] | Balance [%d] \n", root.node_id, root.value, root.height, root.balance)
	preorder(root.left)
	preorder(root.right)
}

func main() {
	var root *node
	for i := 0; i < 10; i++ {
		root = insert(rune(rand.Intn(100)), root)
	}
	preorder(root)
}
