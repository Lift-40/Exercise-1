package main

import (
    . "fmt"
    "runtime"
    "time"
)

var notZero int32

func thread1() {
	for i := 0; i < 1000000; i++ {
		notZero += 1
	}
	Println("Thread 1:")
	Println(notZero)
}

func thread2() {
	for i := 0; i < 1000000; i++ {
		notZero -= 1
	}
	Println("Thread 1:")
	Println(notZero)
}

func main() {
    runtime.GOMAXPROCS(runtime.NumCPU())
	
    go thread1()
	go thread2()
	
    time.Sleep(100*time.Millisecond)
	Println("Result: ")
    Println(notZero)
	time.Sleep(10000*time.Millisecond)
}
