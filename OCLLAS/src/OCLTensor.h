/*
 * OCLTensor.h
 *
 *  Created on: Jul 2, 2012
 *      Author: Chris
 */

#ifndef OCLTENSOR_H_
#define OCLTENSOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <boost/multi_array.hpp>
#include "OCLDataObject.h"

namespace ocllas {

template<typename T, std::size_t RANK>
class OCLTensor : public boost::multi_array<T,RANK>, public OCLDataObject{
private:
	typedef boost::multi_array<T,RANK> Array_t;
	typedef boost::detail::multi_array::extent_gen<RANK> Extents;
	typedef boost::array<Array_t::index, RANK> Shape;

	static Shape getShape(std::vector<unsigned int> v){
		Shape shape;
		for(unsigned int i=0; i<v.size(); ++i){
			shape[i] = v[i];
		}
		return shape;
	}
public:

	OCLTensor(std::vector<unsigned int> shape)
	: Array_t(OCLTensor::getShape(shape))
	{
		std::cout << "OCLTensor constructor" << std::endl;
	}
	virtual ~OCLTensor(){}


	std::string toString(void){
//		Array_t::array_view<RANK> view = this;
		//return this->toString<RANK>(view);
		std::string s = "hello";
		return s;
	}


};


} /* namespace ocllas */
#endif /* OCLTENSOR_H_ */
