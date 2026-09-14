all: oppgave1 oppgave2 multilogger tekst binary_out

oppgave1: losning1.c
	gcc losning1.c -o oppgave1

oppgave2: losning2.h losning2_lese.c losning2_skrive.c
	gcc losning2_skrive.c -o oppgave2_skriver
	gcc losning2_lese.c -o oppgave2_leser

multilogger: multilogger.c log_server.c
	gcc multilogger.c -o multilogger
	gcc log_server.c -o multilogger_server

tekst: tekst.c
	gcc tekst.c -o tekst

binary_out: binary_out.c
	gcc binary_out.c -o binary_out
