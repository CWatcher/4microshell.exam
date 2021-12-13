make || exit 1

./aa /bin/echo
./aa /bin/echo 1

./aa /bin/echo 1 ";" /bin/echo 2
./aa /bin/echo 3 ";"
./aa ";" /bin/echo 4
./aa /bin/echo 5 ";" ";" /bin/echo 6

./aa /bin/echo a "|" /usr/bin/wc -w
./aa /bin/echo a b "|" /usr/bin/wc -w "|" /usr/bin/sed
./aa /bin/echo 6 "|" /bin/cat
./aa cd / ";" /bin/pwd

./aa /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
./aa /bin/echo WOOT "; /bin/echo NOPE;" "; ;" ";" /bin/echo YEAH

./aa asdf
./aa main.c
