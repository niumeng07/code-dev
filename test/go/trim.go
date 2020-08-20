package main

import (
	"fmt"
	"strings"
)

func main() {
	a := "abcdef"
	b := strings.TrimRight(a, "")
	fmt.Println(b)
}
