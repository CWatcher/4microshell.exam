make || exit 1

./aa /bin/echo
./aa /bin/echo 1
./aa /bin/sleep 2; /bin/echo 2
./aa /bin/echo 3; /bin/echo 4;

./aa asdf
./aa main.c
