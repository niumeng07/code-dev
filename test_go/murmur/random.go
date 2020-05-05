package main

import (
	"./github.com/spaolacci/murmur3"
	"fmt"
	"math/rand"
	"time"
)

var letters = []rune("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-=+*/")

func GetRandomString(n int) string {
	b := make([]rune, n)
	for i := range b {
		rand.Seed(int64(time.Now().UnixNano()))
		b[i] = letters[rand.Intn(len(letters))]
	}
	return string(b)
}

func main() {

	for i := 0; i < 1; i++ {
		b := GetRandomString(25)
		c := GetRandomString(25)
		d := GetRandomString(25)
		e := GetRandomString(25)
		murmur := uint32(murmur3.Sum32WithSeed([]byte(b), 0))
		murmur_float := float64(murmur%1000) / 1000
		fmt.Println(b, murmur, murmur_float)

		murmur = uint32(murmur3.Sum32WithSeed([]byte(c), 0))
		murmur_float = float64(murmur%1000) / 1000
		fmt.Println(c, murmur, murmur_float)

		murmur = uint32(murmur3.Sum32WithSeed([]byte(d), 0))
		murmur_float = float64(murmur%1000) / 1000
		fmt.Println(d, murmur, murmur_float)

		murmur = uint32(murmur3.Sum32WithSeed([]byte(e), 0))
		murmur_float = float64(murmur%1000) / 1000
		fmt.Println(e, murmur, murmur_float)

	}
	fmt.Println(uint32(murmur3.Sum32WithSeed([]byte("KclcMyNNt+x2GcS3i/eKVc+0P"), 0)))
	fmt.Println(uint32(murmur3.Sum32WithSeed([]byte("KclcMyNNt+x2GcS3i/eKVc+0Q"), 0)))
	fmt.Println(uint32(murmur3.Sum32WithSeed([]byte("KClcMyNNt+x2GcS3i/eKVc+0Q"), 0)))
}
