package main

import (
	"fmt"
	"math/rand"
	"time"
)

func GenerateRangeNum(min int, max int) int {
	rand.Seed(time.Now().UnixNano()) //单位是秒
	randNum := rand.Intn(max - min)
	randNum = randNum + min
	return randNum
}

func main() {
	fmt.Println(GenerateRangeNum(1, 100))
	fmt.Println(GenerateRangeNum(1, 100))
	fmt.Println(GenerateRangeNum(1, 100))
	fmt.Println(GenerateRangeNum(1, 100))
	fmt.Println(GenerateRangeNum(1, 100))
	fmt.Println(GenerateRangeNum(1, 100))
	fmt.Println(GenerateRangeNum(1, 100))
	fmt.Println(GenerateRangeNum(1, 100))
	fmt.Println(GenerateRangeNum(1, 100))
}
