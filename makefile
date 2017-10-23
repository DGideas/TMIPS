productive_build = g++ tmips.cpp -o tmips --std=c++11 -O3
test_build = g++ tmips.cpp -o tmips --std=c++11 -O0
binary_clean = rm tmips
build: tmips.cpp
	$(productive_build)
t: tmips.cpp
	$(test_build)
	$(binary_clean)
test: tmips.cpp
	$(test_build)
	./tmips
	$(binary_clean)
clean:
	$(binary_clean)
commit:
	git add -A .
	git commit -m "minor changes and improvements"
	git push