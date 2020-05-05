CURRPATH=`pwd`
export GOPATH=$CURRPATH

go get github.com/spaolacci/murmur3.git

go build ./test.go

