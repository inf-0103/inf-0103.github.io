MD = $(shell find . | grep index.md)
HTML := $(patsubst %.md,%.html,$(MD))

%.html: %.md
	pandoc -s $< -o $@ --metadata title="INF-0103"

all: $(HTML)

serve: all
	python3 -m http.server 8000

.PHONY:
clean:
	rm -f index.html
