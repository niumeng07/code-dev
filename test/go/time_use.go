package main

import (
	"./murmur/github.com/spaolacci/murmur3"
	"fmt"
	"math/rand"
	"strconv"
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

func BKDRHash(str string) string {
	seed := uint64(131) // 31 131 1313 13131 131313 etc..
	hash := uint64(0)
	for i := 0; i < len(str); i++ {
		hash = (hash * seed) + uint64(str[i])
	}
	return strconv.FormatUint(hash, 10)
}

func test(iteration int) {
	var all_tim [10]float64
	for i := 0; i < iteration; i++ {
		a := GetRandomString(10)
		b := GetRandomString(50)
		start := time.Now()
		c1 := a + b
		elapsed := time.Since(start)
		all_tim[0] += float64(elapsed) / 1000.0 / 1000.0

		start = time.Now()
		c2 := BKDRHash(a)
		elapsed = time.Since(start)
		all_tim[1] += float64(elapsed) / 1000.0 / 1000.0

		f1 := murmur3.Sum32WithSeed([]byte(a), 0)
		f2 := murmur3.Sum32WithSeed([]byte(b), 0)
		f3 := murmur3.Sum32WithSeed([]byte(b), 0)
		start = time.Now()
		d := f1 + f2
		elapsed = time.Since(start)
		all_tim[2] += float64(elapsed) / 1000.0 / 1000.0

		start = time.Now()
		e1 := murmur3.Sum32WithSeed([]byte(a), 0)
		elapsed = time.Since(start)
		all_tim[3] += float64(elapsed) / 1000.0 / 1000.0

		start = time.Now()
		g1 := strconv.Itoa(int(e1))
		elapsed = time.Since(start)
		all_tim[4] += float64(elapsed) / 1000.0 / 1000.0

		h1 := rand.Float64()
		h2 := rand.Float64()
		start = time.Now()
		h := h1 + h2
		elapsed = time.Since(start)
		all_tim[5] += float64(elapsed) / 1000.0 / 1000.0
		_ = c1
		_ = c2
		_ = d
		_ = e1
		_ = f3
		_ = g1
		_ = h
	}
	fmt.Println(fmt.Sprintf("%10d", iteration), " str+str, BKDR, bigint+, murmur, toString, ", all_tim)

}
func main() {
	test(1)
	test(1000)
	test(10000)
	test(100000)
	test(1000000)
}
