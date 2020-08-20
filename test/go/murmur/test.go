package main

import (
	"./github.com/spaolacci/murmur3"
	"bufio"
	"fmt"
	"io"
	"math/rand"
	"os"
	"strings"
	"time"
)

var letters = []rune(" 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-=+*/")

func GetRandomString(n int) string {
	b := make([]rune, n)
	for i := range b {
		rand.Seed(int64(time.Now().UnixNano()))
		b[i] = letters[rand.Intn(len(letters))]
	}
	return string(b)
}

func BKDRHash(str string) uint64 {
	seed := uint64(131) // 31 131 1313 13131 131313 etc..
	hash := uint64(0)
	for i := 0; i < len(str); i++ {
		hash = (hash * seed) + uint64(str[i])
	}
	//return strconv.FormatUint(hash, 10)
	return hash
}

func BKDRHash2(strs_list []string) uint64 {
	seed := uint64(131) // 31 131 1313 13131 131313 etc..
	hash := uint64(0)
	for j := 0; j < len(strs_list); j++ {
		for i := 0; i < len(strs_list[j]); i++ {
			hash = (hash * seed) + uint64(strs_list[j][i])
		}
	}
	return hash
}

func main() {

	var strs_list = []string{"asdfasf", "fdsfadf", "dfasdf"}
	fmt.Println(BKDRHash2(strs_list))
	return
	fmt.Println(BKDRHash("http://blog.csdn.net/bojie5744"))
	var all_tim [10]float64
	iteration := 10000

	start := time.Now()
	elapsed := time.Since(start)

	for i := 0; i < iteration; i++ {
		b := GetRandomString(25)
		//fmt.Println(b)
		start = time.Now()
		bkdr := BKDRHash(b)
		elapsed = time.Since(start)
		all_tim[0] += float64(elapsed) / 1000.0 / 1000.0
		_ = bkdr
		start = time.Now()
		murmur := uint64(murmur3.Sum32WithSeed([]byte(b), 0))
		elapsed = time.Since(start)
		all_tim[1] += float64(elapsed) / 1000.0 / 1000.0
		_ = murmur
	}
	fmt.Println(all_tim)

	f, err := os.Open("randomStrings")
	if err != nil {
		fmt.Println("open file error")
	}
	defer f.Close()

	rd := bufio.NewReader(f)
	for {
		line, err := rd.ReadString('\n') //以'\n'为结束符读入一行
		if err != nil || io.EOF == err {
			break
		}
		line = strings.Replace(line, "\n", "", -1)
		bkdr := BKDRHash(line)
		murmur := uint64(murmur3.Sum32WithSeed([]byte(line), 0))
		_ = bkdr
		_ = murmur
		fmt.Println(bkdr)
		break
	}
}
