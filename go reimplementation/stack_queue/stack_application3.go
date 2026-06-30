package main

import (
	"fmt"
)

var stack []rune

func Parenthesses_check(stack_ []rune) {
	var temp_stack []rune
	for i := 0; i < len(stack_); i++ {
		char := stack_[i]
		if char == '(' || char == '{' || char == '[' {
			push(&temp_stack, char)
			continue
		}
		switch top(temp_stack) {
		case '(':
			if char == ')' {
				pop(&temp_stack)
			} else {
				push(&temp_stack, char)
			}
		case '{':
			if char == '}' {
				pop(&temp_stack)
			} else {
				push(&temp_stack, char)
			}
		case '[':
			if char == ']' {
				pop(&temp_stack)
			} else {
				push(&temp_stack, char)
			}
		default:
			push(&temp_stack, char)
		}
	}
	if len(temp_stack) == 0 {
		fmt.Println("Parenthesses is correct ")
	} else {
		fmt.Println("Parrenthesses is wrong ")
	}
}
func top(stack_ []rune) rune {
	if len(stack_) == 0 {
		fmt.Println("stack is empty {top}")
		return 0
	}
	return stack_[len(stack_)-1]
}
func push(stack_ *[]rune, char rune) {
	*stack_ = append(*stack_, char)
}
func pop(stack_ *[]rune) {
	if len(*stack_) == 0 {
		fmt.Println("Stack underflow")
		return
	}

	s := *stack_
	// fmt.Println("Popped : ", s[len(s)-1])
	*stack_ = s[:len(s)-1]

}

func main() {
	fmt.Printf("Parenthesses Check \n")
	fmt.Printf("Enter the Imput :\t")
	var input string
	fmt.Scanln(&input)
	stack = []rune(input)
	Parenthesses_check(stack)

}
