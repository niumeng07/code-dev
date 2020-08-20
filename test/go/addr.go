package main

import (
	"fmt"
)

type Offer struct {
	CampaignId string
}

func meth() ([]*Offer, *Offer) {
	offer1 := &Offer{
		CampaignId: "123",
	}
	offer2 := &Offer{
		CampaignId: "abc",
	}
	var offer1_list []*Offer
	offer1_list = append(offer1_list, offer1)
	offer1_list = append(offer1_list, offer1)
	return offer1_list, offer2
}
func main() {

	offer1_list, offer2 := meth()
	fmt.Println(len(offer1_list))
	fmt.Println("--------------------------------")
	for xx, yy := range offer1_list {
		fmt.Println(xx, "-------", yy)
	}
	fmt.Println("--------------------------------")
	fmt.Println(offer2)
	fmt.Println("--------------------------------")
	var x = make([]string, 0, 200)
	x = append(x, "123")
	fmt.Println(x)
	fmt.Println(len(x))
}
