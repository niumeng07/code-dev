package main

import (
	"fmt"
)

type Person struct {
	name string
}

func Get() []*Person {
	return nil
}
func main() {
	fmt.Println("test")
	value := make([]interface{}, 0)
	value = append(value, Get())

	_ = value
}
