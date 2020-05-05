package main

import (
	"fmt"
	"reflect"
)

func main() {
	x := 1
	fmt.Println(reflect.TypeOf(x))
	y := "string"
	fmt.Println(reflect.TypeOf(y))

	//fmt.Println(reflect.Type(x))
}
