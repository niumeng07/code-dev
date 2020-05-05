package main

import (
	"fmt"
)

type Person struct {
	name string
}

func main() {
	P := Person{"狗子"}
	Interface := []interface{}{&P}
	Users := []*Person{&P}
	_ = Users
	Item2 := []interface{}{&P}
	Interface = append(Interface, Item2...)
	for a, b := range Interface {
		fmt.Println(a, b)
	}
}
