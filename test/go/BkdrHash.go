package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

type BkdrHash struct {
	hashValue int64
}

func newBkdrHash() BkdrHash {
	var factory BkdrHash
	factory.hashValue = 0
	return factory
}

var seed = int64(131) // 31 131 1313 13131 131313 etc..
var hash = int64(0)

func (this *BkdrHash) AddBkdrHash(str string) int64 {
	for i := 0; i < len(str); i++ {
		this.hashValue = (this.hashValue * seed) + int64(str[i])
	}
	return this.hashValue
}
func (this *BkdrHash) ResetHash() {
	this.hashValue = 0
}

func (this *BkdrHash) GetSingHash(str string) int64 {
	hash = int64(0)
	for i := 0; i < len(str); i++ {
		hash = (hash * seed) + int64(str[i])
	}
	return hash
}

func main() {
	hashFactory := newBkdrHash()
	b := ""
	start := time.Now()
	for i := 0; i < 10000; i++ {
		hashFactory.AddBkdrHash("id")
		hashFactory.AddBkdrHash("=")
		hashFactory.AddBkdrHash("123")
		hashFactory.AddBkdrHash("model")
		hashFactory.AddBkdrHash("=")
		hashFactory.AddBkdrHash("iphone")
		b = strconv.FormatInt(hashFactory.hashValue, 10)
		hashFactory.ResetHash()
	}
	elapsed := time.Since(start)
	fmt.Println(elapsed)

	start = time.Now()
	for i := 0; i < 10000; i++ {
		b = "id" + "=" + strconv.FormatInt(hashFactory.GetSingHash("123"), 10) + "model" + "=" + strconv.FormatInt(hashFactory.GetSingHash("iphone"), 10)
		hashFactory.ResetHash()
	}
	elapsed = time.Since(start)
	fmt.Println(elapsed)

	fmt.Print("test end.")
	_ = b
	return

}
