# Really simple makefile, focused on MacOS to start.

CPPOPTS +=
COPTS +=
LDOPTS += -framework opencl

cl_enumerate_devs: cl_enumerate_devs.cc
	g++ -o $@ $< $(LDOPTS)
