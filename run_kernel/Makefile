# Really simple makefile, focused on MacOS to start.

CPPOPTS +=
COPTS +=
LDOPTS += -framework opencl

cl_run_kernel: cl_run_kernel.cc
	g++ -o $@ $< $(LDOPTS)
