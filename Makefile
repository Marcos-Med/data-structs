all:
	gcc -c src/codes/ListSeq.c -I include -o obj/ListSeq.o
	gcc -c src/codes/ListSeqOrd.c -I include -o obj/ListSeqOrd.o
	gcc -c src/codes/LinkedList.c -I include -o obj/LinkedList.o
	gcc -c src/files_aux/functions_aux.c -I include -o obj/functions_aux.o
	gcc app/main.c obj/*.o -I include -o bin/app
run:
	echo "Rodando um programa"
#clean:
#	Remove-Item -Recurse -Force .\bin\*
#	Remove-Item -Recurse -Force .\obj\*