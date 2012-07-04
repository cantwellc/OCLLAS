/*
 * GPUObject.h
 *
 *  Created on: Jul 3, 2012
 *      Author: Chris
 */

#ifndef GPUOBJECT_H_
#define GPUOBJECT_H_

#include "OCLObject.h"
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

namespace ocl {

class GPUObject : public OCLObject{
public:
	GPUObject(){
		std::string info;

		std::vector<cl::Platform> pList;
		std::vector<cl::Device> dList;

		cl::Platform::get(&pList);
		cl::Platform p = pList[0];
		p.getInfo((cl_platform_info)CL_PLATFORM_NAME, &info);
		std::cout << "Initializing OpenCL object to run on platform: " << info << std::endl;
		p.getInfo((cl_platform_info)CL_PLATFORM_EXTENSIONS, &info);
		std::cout << "Supported optional extensions: " << std::endl << info << std::endl;

		p.getDevices(CL_DEVICE_TYPE_GPU, &dList);
		assert(0<dList.size());
		std::cout << std::endl << "Initializing OpenCL object to run on " << dList.size() << " device(s):" << std::endl;
		for(unsigned int i=0; i<dList.size(); i++)
		{
			dList[i].getInfo((cl_device_info)CL_DEVICE_NAME, &info);
			std::cout << "Name: " << info << std::endl;

			cl_uint deviceMaxWorkGroupSize;
			dList[i].getInfo((cl_device_info)CL_DEVICE_MAX_WORK_GROUP_SIZE, &deviceMaxWorkGroupSize);
			std::cout << "Max Work Group Size: " << deviceMaxWorkGroupSize << std::endl;

			cl_uint deviceMaxWorkItemDimensions;
			dList[i].getInfo((cl_device_info)CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, &deviceMaxWorkItemDimensions);
			std::cout << "Max Work Item Dimensions: " << deviceMaxWorkItemDimensions << std::endl;

			std::vector<cl_uint> deviceMaxWorkItemSizes;
			dList[i].getInfo((cl_device_info)CL_DEVICE_MAX_WORK_ITEM_SIZES, &deviceMaxWorkItemSizes);
			std::cout << "Max Work Item Sizes: "
				<< deviceMaxWorkItemSizes[0] << " " << deviceMaxWorkItemSizes[1] << " " << deviceMaxWorkItemSizes[2] << std::endl;
		}

		cl_context_properties cp[3] = {
			CL_CONTEXT_PLATFORM,
			(cl_context_properties)(p)(),
			0
		};
	}
	virtual ~GPUObject(){

	}
};

} /* namespace ocl */
#endif /* GPUOBJECT_H_ */
