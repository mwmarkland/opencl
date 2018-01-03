/**
   \file cl_run_kernel.cc

   \brief Create and run a simple OpenCL kernel.

   On MacOS add `-framework opencl` to get the correct linking options.
 */

// This is where Apple keeps its headers.
#include <OpenCL/cl.h>
#include <iostream>


int main(int argc,char *argv[])
{

  cl_int rc = 0;
  
  // Retrieve information about the OpenCL Platform.
  cl_uint platformCount = 0;
  cl_platform_id *platformIDList = new cl_platform_id[256];

  rc = clGetPlatformIDs(256,platformIDList,&platformCount);
  if(rc == CL_SUCCESS) {
    std::cout << "platformCount = " << platformCount << std::endl;
  }


  // Create a context for a device.

  cl_context theContext = 0;

  // Assuming there is a GPU device to create from.
  theContext = clCreateContextFromType(NULL,CL_DEVICE_TYPE_GPU,NULL,NULL,&rc);

  if(rc == CL_SUCCESS) {
    std::cout << "GPU Context Created." << std::endl;
  }

  // Retrieve the list of devices from the context.
  cl_device_id *deviceList = new cl_device_id[256];
  size_t deviceCount = 0;
  
  rc = clGetContextInfo(theContext,
                        CL_CONTEXT_DEVICES,
                        256,
                        deviceList,
                        &deviceCount);

  if(rc == CL_SUCCESS) {
    std::cout << "Number of devices = " << deviceCount << std::endl;
  }

  // Cleanup context
  rc = clReleaseContext(theContext);
  if(rc == CL_SUCCESS) {
    std::cout << "Context released." << std::endl;
  }
  
  // Cleanup memory use.
  delete[] platformIDList;
  delete[] deviceList;
  platformIDList = 0;
  deviceList = 0;
  return 0;
}


   
  
