BASEFILES := header.md a1.md 
SOLFILES := a1_sol.md

.PHONY: all sol exam
all: exam.pdf
exam: exam.pdf
sol: exam_sol.pdf

temp_exam.md: $(BASEFILES)
	( \
		cat header.md; \
		echo '\n## Oppgave 1 (100%)\n'; \
		cat a1.md; \
	) >> temp_exam.md

temp_sol.md: $(BASEFILES) $(SOLFILES)
	( \
		cat header.md; \
		echo '\n## Oppgave 1 (100%)\n'; \
		cat a1.md; \
		cat a1_sol.md; \
	) >> temp_sol.md

exam.pdf: temp_exam.md
	pandoc temp_exam.md -o exam.pdf
	rm temp_exam.md

exam_sol.pdf: temp_sol.md
	pandoc temp_sol.md -o exam_sol.pdf
	rm temp_sol.md

.PHONY: clean
clean:
	rm -f temp_exam.md temp_sol.pdf exam.pdf exam_sol.prd
