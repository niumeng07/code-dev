package main

import (
	"fmt"
)

func main() {
	var x []string
	fmt.Println(x)
	for a, b := range x {
		fmt.Println(a, b)
	}
}
