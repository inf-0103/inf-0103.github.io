MD = $(shell find . | grep index.md)
HTML := $(patsubst %.md,%.html,$(MD))

%.html : %.md
	pandoc -s $< -o $@ --metadata title="INF-0103"

all: $(HTML)

.PHONY:
clean:
	rm -f index.html
