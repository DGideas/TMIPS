build: tmips.cpp
	g++ tmips.cpp -o tmips --std=c++11 -O3
test: tmips.cpp
	g++ tmips.cpp -o tmips --std=c++11 -O0
	rm tmips
clean:
	rm tmips
commit:
	git add -A .
	git commit -m "minor changes and improvements"
	git push