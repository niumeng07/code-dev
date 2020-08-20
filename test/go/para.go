package main

import (
	"fmt"
	"strings"
)

func test(x string, y string, names ...string) string {
	fmt.Println(x, y)
	for _, x := range names {
		fmt.Println(x)
	}
	return strings.Join(names, "|")
}

func main() {
	x := test("1", "2", "a", "b", "c", "d")
	fmt.Println(x)
}
