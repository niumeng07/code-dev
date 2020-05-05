package main

import (
	"fmt"
	//"strconv"
	//"strings"
)

func main() {
	var template_map_list = make(map[int64][]string)
	template_map_list[1] = make([]string, 0, 200)
	template_map_list[2] = make([]string, 0, 200)
	template_map_list[3] = make([]string, 0, 200)
	template_map_list[1] = append(template_map_list[1], "1")
	template_map_list[1] = append(template_map_list[1], "2")

	a, b := template_map_list[1]
	fmt.Println(a, b)
	cc := "123"
	fmt.Println(cc)
	cc = 1233
	fmt.Println(cc)
}
