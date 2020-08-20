package main

import (
	"fmt"
)

func main() {
	var x = "ab"
	if x[0:1] == "a" {
		fmt.Println("--")
	}
	fmt.Println(x[0:1] + "adfa")
	fmt.Println(x[0:1])
}
