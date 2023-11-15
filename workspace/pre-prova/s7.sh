#!/bin/bash

echo -e "\nTestando valores"
out/7 <<< "0"
out/7 <<< "1"
out/7 <<< "2"
out/7 <<< "3"
out/7 <<< "4"
out/7 <<< "33"
out/7 <<< "1023"
echo -e "\nTestando erros"
out/7 <<< "-1"
out/7 <<< "1024"
