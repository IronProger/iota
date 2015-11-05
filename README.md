# iota

Простой cчетчик вызовов для shell скриптов.
За каждый вызов перезаписывает число в /tmp/iota.number, прибавляя еденицу, либо создаёт данный файл, если он отсутствует. Умеет обнулять и печатать текущее значение.


# For run #

Download the source code by running the following code in your command prompt:

$ git clone https://github.com/IronProger/iota

or simply copy all text from one source file, after

$ gcc iota.c -o iota
$ ./iota

also, you can copy binary into your $PATH


# Example #

$ iota; iota; iota; iota
$ iota get
output: 4

$ function fuu
$   iota null
$   for i in (seq 256)
$     iota
$   end
$   iota get
$ end
output: 256
PS it's a fish shell syntax

>***$ go run main.go***

or
>***$ go build main.go***

>***$ ./main***

for help type

>***$ ./main --help***
