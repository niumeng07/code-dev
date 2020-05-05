package main

import (
	"fmt"
)

func process(featureMap map[string]map[string]int) map[string]map[string]int {
	featureMap["city"]["2"] = 1
	featureMap["ak"] = make(map[string]int)
	featureMap["ak"]["9"] = 1
	return featureMap
}
func main() {
	featureMap := make(map[string]map[string]int)
	featureMap["id"] = make(map[string]int)
	featureMap["id"]["1234566"] = 1
	featureMap["id"]["xxxy566"] = 1
	featureMap["id"]["xxxy566"] = 1
	featureMap["city"] = make(map[string]int)
	featureMap["city"]["1"] = 1
	fmt.Println(featureMap, len(featureMap))
	featureMap = process(featureMap)
	fmt.Println(featureMap, len(featureMap))
}
