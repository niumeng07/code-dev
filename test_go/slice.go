package main

import (
	"fmt"
)

type Tuple struct {
	first  string
	second string
}

func NewTuple(p1 string, p2 string) Tuple {
	var result Tuple
	result.first = p1
	result.second = p2
	return result
}

func main() {
	slice1 := make([]Tuple, 5, 10)
	slice1 = append(slice1, NewTuple("1", "1"))
	for _, v := range slice1 {
		fmt.Println(v)
	}
	fmt.Println(len(slice1))
	for x, y := range slice1 {
		fmt.Println(x, ", ", y)
	}
}
