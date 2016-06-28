#include <vector>
#include <cmath>

namespace quiz1{

	template<class T>
	T EuclideanDistance(const std::vector<T>& Pa,
	                    const std::vector<T>& Pb){

		if( Pa.size() != Pb.size() )
			throw ":(";

		T Distance = 0;
		int siz=Pa.size();
		for(int cnt=0;cnt<siz;cnt++){
			T temp;
			temp=Pa[cnt]-Pb[cnt];
			temp*=temp;
			Distance +=temp;
		}
		Distance = sqrt(Distance);
		// Fill your code here

		return Distance;

		}

	}
