compressed: slides.md
	pandoc -t beamer slides.md -o slides_compressed.pdf

slides: slides.md
	pandoc -t beamer -i slides.md -o slides.pdf

clean: 
	rm slides.pdf slides_compressed.pdf

