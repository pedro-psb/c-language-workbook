#!/bin/bash

echo -e "running tests\n"
out/8 <<EOF
5 10 20
1 2 3
1 2 1
EOF
echo -e "\ndone\n"

out/8 <<EOF
2 1 1
1 2 1
1 1 2
EOF
echo -e "\ndone\n"

out/8 <<EOF
1 1 1
1 1 1
1 1 1
EOF
echo -e "\ndone\n"
