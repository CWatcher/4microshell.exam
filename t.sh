make || exit 1

./aa /bin/echo
./aa /bin/echo 1
./aa /bin/sleep 1 ";" /bin/echo 2
./aa /bin/echo 3 ";" /bin/echo 4 ";"
./aa /bin/sleep 5 "|" /bin/echo 5 ";"
./aa /bin/echo 6 "|" /bin/cat
./aa /bin/echo 7 ";" ";" /bin/echo 8
./aa ";" /bin/echo 9

./aa /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
./aa /bin/echo WOOT "; /bin/echo NOPE;" "; ;" ";" /bin/echo YEAH



./aa asdf
./aa main.c
