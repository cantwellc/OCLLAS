/*
 * OCLObject.h
 *
 *  Created on: Jul 3, 2012
 *      Author: Chris
 */

#ifndef OCLOBJECT_H_
#define OCLOBJECT_H_

#include <CL/cl.hpp>

namespace ocl {

class OCLObject {
private:
	cl::Context _context;
	cl::Device _device;
	cl::CommandQueue _queue;

public:
	OCLObject(){
	}
	virtual ~OCLObject(){

	}

	void context(cl::Context c){this->_context=c;}
	cl::Context& context(void){return this->_context;}
	void device(cl::Device d){this->_device=d;}
	cl::Device& device(void){return this->_device;}
	void queue(cl::CommandQueue q){this->_queue=q;}
	cl::CommandQueue& queue(void){return this->_queue;}

};

} /* namespace ocl */
#endif /* OCLOBJECT_H_ */
