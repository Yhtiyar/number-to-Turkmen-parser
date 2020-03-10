# number-to-Turkmen-parser
Parsing number to Turkmen language

### Usage : 
~~~
#include "converter.cpp"
...
int main() {
  ...
  long long number = 32145;
  string answer = convert_to_turkmen(number);
  ...
}
...
~~~
### Requirtments

Parsing number should be less than `10^15`
 
Also can be used for parsing negative numbers, it should be greater than `-10^15`

Otherwise, you will get `Error` as string

## How to run example:
In linux :

Open terminal in directory where you downloaded source and type

`g++ -o main.o main.cpp`

`g++ ./main.o`
