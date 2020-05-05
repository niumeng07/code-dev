package main

import (
	"fmt"
)

func meth(i uint8) (x uint8, a [3]string) {
	x1 := [3]string{}
	x1[0] = "x"
	x1[1] = "y"
	x1[2] = "z"
	return 99, x1
}

type ss struct {
	ivr float64
}

func main() {
	var list []ss
	s := ss{0.1}
	list = append(list, s)
	s = ss{0.02}
	list = append(list, s)
	s = ss{0.3}
	list = append(list, s)
	s = ss{0.22}
	list = append(list, s)
	fmt.Println(list)
}
