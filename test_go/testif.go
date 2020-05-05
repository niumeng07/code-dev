package main

import (
	"fmt"
)

func main() {
	var v map[string]string
	if _, ok := v[v["1"]]; ok && false {
		fmt.Println(1)
	}
}
