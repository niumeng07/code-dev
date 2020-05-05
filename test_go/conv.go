package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s uint64 = 9999999999999999999
	fmt.Println(strconv.Itoa(int(s)))
	var ss string
	ss = strconv.FormatUint(s, 10)
	fmt.Println(ss)
}
