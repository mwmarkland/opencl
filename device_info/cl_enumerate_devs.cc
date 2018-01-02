/**
   \file cl_enumerate_devs.cc

   \brief Enumerate the OpenCL devices on a machine. 

   Initial code is not very general; focused on MacOS and knowing that
   there are really only one of each device type querried. Should
   serve as a starting point.

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

  char *returnBuffer = new char[2048];
  memset(returnBuffer,'\0',2048);
  
  size_t retSize = 0;
  
  rc = clGetPlatformInfo(platformIDList[0],
                         CL_PLATFORM_PROFILE,
                         2048,
                         returnBuffer,
                         &retSize);

  if(rc == CL_SUCCESS) {
    std::cout << "PROFILE: " << returnBuffer << std::endl;
  }

  memset(returnBuffer,'\0',2048);
  rc = clGetPlatformInfo(platformIDList[0],
                         CL_PLATFORM_VERSION,
                         2048,
                         returnBuffer,
                         &retSize);

  if(rc == CL_SUCCESS) {
    std::cout << "VERSION: " << returnBuffer << std::endl;
  }

  memset(returnBuffer,'\0',2048);
  rc = clGetPlatformInfo(platformIDList[0],
                         CL_PLATFORM_NAME,
                         2048,
                         returnBuffer,
                         &retSize);

  if(rc == CL_SUCCESS) {
    std::cout << "NAME: " << returnBuffer << std::endl;
  }

  memset(returnBuffer,'\0',2048);
  rc = clGetPlatformInfo(platformIDList[0],
                         CL_PLATFORM_VENDOR,
                         2048,
                         returnBuffer,
                         &retSize);

  if(rc == CL_SUCCESS) {
    std::cout << "VENDOR: " << returnBuffer << std::endl;
  }

  // Let's get a list of devices.

  cl_device_id *deviceList = new cl_device_id[256];
  cl_uint deviceCount = 0;
  rc = clGetDeviceIDs(platformIDList[0],
                      CL_DEVICE_TYPE_ALL,
                      256,
                      deviceList,
                      &deviceCount);
  if(rc == CL_SUCCESS) {
    std::cout << "CL_DEVICE_TYPE_ALL = " << deviceCount << std::endl;
  }

  rc = clGetDeviceIDs(platformIDList[0],
                      CL_DEVICE_TYPE_CPU,
                      256,
                      deviceList,
                      &deviceCount);
  if(rc == CL_SUCCESS) {
    std::cout << "CL_DEVICE_TYPE_CPU = " << deviceCount << std::endl;
  }

  cl_uint vendorID = 0;
  memset(returnBuffer,'\0',2048);
  rc = clGetDeviceInfo(deviceList[0],
                       CL_DEVICE_VENDOR_ID,
                       sizeof(cl_uint),
                       &vendorID,
                       &retSize);
  if(rc == CL_SUCCESS) {
    std::cout << "\t" << "CL_DEVICE_VENDOR_ID = " << vendorID << std::endl;
  }

  cl_uint computeUnits = 0;
  rc = clGetDeviceInfo(deviceList[0],
                       CL_DEVICE_MAX_COMPUTE_UNITS,
                       sizeof(cl_uint),
                       &computeUnits,
                       &retSize);
  if(rc == CL_SUCCESS) {
    std::cout << "\t" << "CL_DEVICE_MAX_COMPUTE_UNITS = " << computeUnits << std::endl;
  }


  rc = clGetDeviceIDs(platformIDList[0],
                      CL_DEVICE_TYPE_GPU,
                      256,
                      deviceList,
                      &deviceCount);
  if(rc == CL_SUCCESS) {
    std::cout << "CL_DEVICE_TYPE_GPU = " << deviceCount << std::endl;
  }
  
  vendorID = 0;
  memset(returnBuffer,'\0',2048);
  rc = clGetDeviceInfo(deviceList[0],
                       CL_DEVICE_VENDOR_ID,
                       sizeof(cl_uint),
                       &vendorID,
                       &retSize);
  if(rc == CL_SUCCESS) {
    std::cout << "\t" << "CL_DEVICE_VENDOR_ID = " << vendorID << std::endl;
  }

  computeUnits = 0;
  rc = clGetDeviceInfo(deviceList[0],
                       CL_DEVICE_MAX_COMPUTE_UNITS,
                       sizeof(cl_uint),
                       &computeUnits,
                       &retSize);
  if(rc == CL_SUCCESS) {
    std::cout << "\t" << "CL_DEVICE_MAX_COMPUTE_UNITS = " << computeUnits << std::endl;
  }

  return 0;
}


   
  
