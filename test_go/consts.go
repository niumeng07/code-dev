package main

import (
	"fmt"
)

func itest(m map[string]string, i int) map[string]string {
	fmt.Println(1)
	m["1"] = "1"
	return m
}
func main() {
	m := make(map[string]string)
	m["2"] = "2"
	fmt.Println(m)
	itest(m, 1)
	fmt.Println(m)

	var x int64 = 123456
	if x == 123456 {
		fmt.Println("equal")
	}
}
