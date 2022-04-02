export opts=-D_FORTIFY_SOURCE=2 -fno-diagnostics-show-option		\
    -fstack-protector-all -g -O3 -std=c++14 -Walloc-zero -Walloca	\
    -Wctor-dtor-privacy -Wduplicated-cond -Wduplicated-branches		\
    -Werror -Wextra -Wfatal-errors -Winit-self -Wlogical-op		\
    -Wold-style-cast -Wpedantic -Wshadow -Wunused-const-variable=1	\
    -Wzero-as-null-pointer-constant
CXXFLAGS=-Wall $$opts
# Use CXXFLAGS; not CPPFLAGS.  CXX is for C++, CPP is for the C Pre-Processor.

assignment=cypher
tar_name=cypher

$(assignment): $(assignment).o
	g++ $(CXXFLAGS) -o $@ $^

tar:
	tar -cv $(MAKEFILE_LIST) *.cc $(wildcard *.h) README.txt >$(assignment).tar

clean:
	rm -f $(assignment) $(assignment).tar *.o *.gch *.gcov a.out