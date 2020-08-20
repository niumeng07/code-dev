package main

import (
	"math/rand"
	//"runtime"
	"time"
)

/*
#include <stdio.h>
*/
import "C"

var letters = []rune("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-=+*/")

func GetRandomString(n int) string {
	b := make([]rune, n)
	for i := range b {
		rand.Seed(int64(time.Now().UnixNano()))
		b[i] = letters[rand.Intn(len(letters))]
	}
	return string(b)
}

/* 测试程序中有大量Map时导致的GC问题
 */
func main() {
	for i := 0; i < 10000; i++ { //pv
		for j := 0; j < 100; i++ { //offer
			testMap := make(map[string]map[string]int)
			for k := 0; k < 300; i++ { //feature
				key := GetRandomString(10)
				key2 := GetRandomString(10)
				testMap[key] = make(map[string]int)
				testMap[key][key2] = 1
			}
			//runtime.GC()
		}
	}
}
