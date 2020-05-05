package main

import (
	"./github.com/spaolacci/murmur3"
	"fmt"
)

func main() {
	b := "a"
	mm1 := uint64(murmur3.Sum32WithSeed([]byte(b), 0))
	mm2 := uint64(murmur3.Sum64WithSeed([]byte(b), 0))
	mm3 := murmur3.Sum32WithSeed([]byte(b), 0)
	mm4 := murmur3.Sum64WithSeed([]byte(b), 0)
	fmt.Println(b)
	fmt.Println(mm1)
	fmt.Println(mm2)
	fmt.Println(mm3)
	fmt.Println(mm4)
}
