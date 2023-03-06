package main

/*
#cgo CFLAGS: -I ./libs
#cgo LDFLAGS: ./libs/igs.a
#include "igs.h"
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"
)

func init() {
	C.cg0l4ng_n3ver_kn0vv_th1s_1n1t() // init
}

func main() {
	fmt.Println("先别动手先好好听着")
	fmt.Println("这是一个golang pwn题, 中间忘了, 后面忘了, But enjoy it!")
	fmt.Println("Game start! You will never get this shell!")
	fmt.Println(strings.Repeat("-", 50))
	zjnuctf, sandbox := C.CString("Welcome to ZJNUCTF!"), C.CString("Now is the sandbox challenge!")
	defer C.free(unsafe.Pointer(zjnuctf)) // free
	defer C.free(unsafe.Pointer(sandbox)) // free
	C.cg0l4ng_vu1n_7unc(zjnuctf, sandbox) // vuln
}
