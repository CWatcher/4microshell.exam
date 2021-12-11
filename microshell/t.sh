make || exit 1

./aa /bin/echo
./aa /bin/echo 1
./aa /bin/sleep 1 ";" /bin/echo 2
./aa /bin/echo 3 ";" /bin/echo 4 ";"
./aa /bin/sleep 5 "|" /bin/echo 5 ";"

./aa asdf
./aa main.c
